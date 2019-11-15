// command_active_object.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <chrono>
#include <assert.h>

using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

class ActiveObjectEngine
{
public:
	void add_command(shared_ptr<Command> cmd)
	{
		commands_.push_back(cmd);
	}

	void run()
	{
		while (!commands_.empty())
		{
			auto cmd = commands_.front();
			commands_.pop_front();
			cmd->execute();
		}
	}

private:
	list<shared_ptr<Command>> commands_;
};

static bool commandExecuted = false;

//class Weakup : public Command
//{
//public:
//	void execute()
//	{
//		commandExecuted = true;
//	}
//};

long long get_current_milliseconds()
{
	auto cur_ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	return cur_ms.count();
}

class SleepCommand 
	: public Command,
	public enable_shared_from_this<SleepCommand>
{
public:
	SleepCommand(long long milliseconds, shared_ptr<ActiveObjectEngine> aoe, shared_ptr<Command> weakup_command)
		: sleepTime_(milliseconds),
		aoe_(aoe),
		weakup_command_(weakup_command),
		startTime_(0),
		started_(false)
	{

	}

	void execute()
	{
		long long currentTime = get_current_milliseconds();
		if (!started_)
		{
			started_ = true;
			startTime_ = currentTime;
			aoe_->add_command(shared_from_this());
		}
		else if ((currentTime - startTime_) < sleepTime_)
		{
			aoe_->add_command(shared_from_this());
		}
		else
		{
			aoe_->add_command(weakup_command_);
		}
	}

private:
	shared_ptr<Command> weakup_command_;
	shared_ptr<ActiveObjectEngine> aoe_;
	long long sleepTime_;
	long long startTime_;
	bool started_;
};

class DelayedTyper
	: public Command,
	public enable_shared_from_this<DelayedTyper>
{
public:
	DelayedTyper(long long delay, char c)
	{
		itsDelay_ = delay;
		itsChar_ = c;
	}

	void execute()
	{
		cout << itsChar_;
		if (!stop_)
		{
			delayAndRepeat();
		}
	}

	void delayAndRepeat()
	{
		shared_ptr<SleepCommand> cmd(new SleepCommand(itsDelay_, aoe_, shared_from_this()));
		aoe_->add_command(cmd);
	}

private:
	long long itsDelay_;
	char itsChar_;

public:
	static shared_ptr<ActiveObjectEngine> aoe_;
	static bool stop_;
};

shared_ptr<ActiveObjectEngine> DelayedTyper::aoe_(new ActiveObjectEngine());
bool DelayedTyper::stop_(false);

class StopCommand
	: public Command
{
public:
	void execute()
	{
		DelayedTyper::stop_ = true;
	}
};

int main()
{
	auto engine = DelayedTyper::aoe_;
	shared_ptr<DelayedTyper> d1(new DelayedTyper(100, '1'));
	shared_ptr<DelayedTyper> d2(new DelayedTyper(300, '3'));
	shared_ptr<DelayedTyper> d3(new DelayedTyper(500, '5'));
	shared_ptr<DelayedTyper> d4(new DelayedTyper(700, '7'));
	engine->add_command(d1);
	engine->add_command(d2);
	engine->add_command(d3);
	engine->add_command(d4);

	shared_ptr<StopCommand> stop_command(new StopCommand());
	shared_ptr<SleepCommand> sleep_command(new SleepCommand(20000, engine, stop_command));
	engine->add_command(sleep_command);
	engine->run();

    std::cout << "Hello World!\n";
}
