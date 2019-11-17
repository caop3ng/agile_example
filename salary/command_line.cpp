#include "command_line.h"
#include <map>
#include <iostream>
#include <assert.h>
#include "salary.h"

using namespace std;

map<string, Command> commands_dict = {
	{ "list" , Command::kList },
	{ "add", Command::kAdd },
	{ "change", Command::kChange },
	{ "help", Command::kHelp },
	{ "exit", Command::kExit },
	{ "clear", Command::kClear },
	{ "timecard", Command::kTimeCard},
	{ "salesreceipt", Command::kSalesReceipt},
	{ "servicecharge", Command::kServiceCharge},
	{ "chgemp", Command::kChgEmp},
};

map<EmployeeProperties, string> properties_descriptor
{
	{ EmployeeProperties::kName, "name" },
	{ EmployeeProperties::kAddress, "address" },
};

command_line::command_line()
{
}

Command command_line::parse(const std::string& text) const
{
	auto trimed_text = triming(text);

	auto it = commands_dict.find(trimed_text);
	if (it == commands_dict.end())
	{
		return Command::kUnknown;
	}
	else
	{
		return commands_dict[trimed_text];
	}

}

bool command_line::exec_command(Command cmd) const
{
	switch (cmd)
	{
	case Command::kHelp:
		return exec_help();
	case Command::kList:
		return exec_list();
	case Command::kAdd:
		return exec_add();
	case Command::kClear:
		return exec_clear();
	case Command::kTimeCard:
		return exec_time_card();
	case Command::kSalesReceipt:
		return exec_sales_receipt();
	case Command::kServiceCharge:
		return exec_service_charge();
	case Command::kChgEmp:
		return exec_chg_emp();
	default:
		assert(0);
		break;
	}

	return false;
}

bool command_line::exec_help() const
{
	cout << "you can use those commands blow: " << endl;
	for (const auto& it : commands_dict)
	{
		cout << it.first << endl;
	}

	return true;
}

bool command_line::exec_list() const
{
	auto employees = salary_db::instance().get_all_employees();

	if (employees.empty())
	{
		cout << "There is no employee." << endl;
		return true;
	}

	cout << "Employee: " << endl;
	for (const auto& e : employees)
	{
		cout << e.to_string() << endl;
	}

	return true;
}

bool command_line::exec_add() const
{
	salary_employee emp;

	cout << "id: ";
	cin >> emp.id;

	cout << "name: ";
	cin >> emp.name;

	cout << "address: ";
	cin >> emp.address;

	while (true)
	{
		cout << "employee type, only number. 1: hourly worker, 2: monthly worker, 3: commissioned worder." << endl;
		cout << "employee type: ";
		int type;
		cin >> type;
		if (IsValidEmployeeType(static_cast<employee_type>(type)))
		{
			emp.emp_type = static_cast<employee_type>(type);
			break;
		}
		else
		{
			cout << "invalid type, number: " << type << ". please re-enter." << endl;
		}
	}
	
	cout << "society dues: ";
	cin >> emp.society_dues;

	emp.service_amount = 0;
	emp.create_time = std::chrono::system_clock::now();

	bool ret = salary_db::instance().add_employee(emp);
	if (ret)
	{
		cout << "Sucessfully add an employee: " << endl;
		cout << emp.to_string() << endl;
	}
	else
	{
		cout << "Failed to add employee." << endl;
	}

	return ret;
}

bool command_line::exec_clear() const
{
	system("cls");
	return true;
}

bool command_line::exec_time_card() const
{
	employee_time_card etc;

	cout << "employee id: ";
	cin >> etc.employee_id;

	cout << "hours: ";
	cin >> etc.hours;

	etc.date_time = chrono::system_clock::now();

	bool ret = salary_db::instance().add_time_card(etc);
	if (!ret)
	{
		cout << "Failed to add time card." << endl;
	}

	return true;
}

bool command_line::exec_sales_receipt() const
{
	sales_receipt sr;
	cout << "employee id: ";
	cin >> sr.employee_id;

	cout << "amount: ";
	cin >> sr.amount;

	sr.date_time = chrono::system_clock::now();

	bool ret = salary_db::instance().add_sales_receipt(sr);
	if (!ret)
	{
		cout << "Failed to add sales receipt." << endl;
	}

	return true;
}

bool command_line::exec_service_charge() const
{
	int member_id;
	cout << "member id: ";
	cin >> member_id;

	int amount;
	cout << "amount: ";
	cin >> amount;

	bool ret = salary_db::instance().service_charge(member_id, amount);
	if (!ret)
	{
		cout << "Failed to add service charge." << endl;
	}

	return true;
}

bool command_line::exec_chg_emp() const
{
	//cout << "employee id: ";
	//int employee_id;
	//cin >> employee_id;

	//cout << "member id: ";
	//int member_id;
	//cin >> member_id;

	//cout << "dues: ";
	//int dues;
	//cin >> dues;

	//bool ret = salary_db::instance().add_member(employee_id, member_id, dues);
	//if (!ret)
	//{
	//	cout << "Failed to add user member." << endl;
	//}
	
	cout << "you can select which property to change." << endl;
	for (EmployeeProperties i = EmployeeProperties::kName; i <= EmployeeProperties::EmployeeProperties_MAX; ++i)
	{
		cout << static_cast<int>(i) << ": " << properties_descriptor[i];
		if (i < EmployeeProperties::EmployeeProperties_MAX)
		{
			cout << ", ";
		}
	}
	cout << endl;
	cout << ">>> ";

	int property;
	while (1)
	{
		cin >> property;
		if (property < static_cast<int>(EmployeeProperties::kName)
			|| property > static_cast<int>(EmployeeProperties::EmployeeProperties_MAX))
		{
			cout << "wrong input, please re-enter" << endl;
			cout << ">>>";
			continue;
		}
		else
		{
			break;
		}
	}

	switch (static_cast<EmployeeProperties>(property))
	{
	case EmployeeProperties::kName:
		return exec_chg_emp_name();
	case EmployeeProperties::kAddress:
		return exec_chg_emp_address();
	default:
		assert(0);
		break;
	}

	return false;
}

bool command_line::exec_chg_emp_name() const
{
	int emp_id;
	cout << "employee id:";
	cin >> emp_id;

	string name;
	cout << "new name: ";
	cin >> name;

	auto& db = salary_db::instance();
	if (db.has_employee(emp_id))
	{
		auto emp = db.get_employee(emp_id);
		emp.name = name;
		bool ret = salary_db::instance().change_employee(emp);
		if (ret)
		{
			cout << "Sucessfully changed employee name." << endl;
		}
		else
		{
			cout << "Failed to change employee name." << endl;
		}
	}
	else
	{
		cout << "Failed to change employee name, employee not exist" << endl;
	}
	
	return true;
}

bool command_line::exec_chg_emp_address() const
{
	return true;
}