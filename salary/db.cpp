#include "db.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;
namespace fs = std::filesystem;

bool salary_db::open(const std::string& filename)
{
	if (!fs::exists(filename))
	{
		return false;
	}

	if (!fs::is_regular_file(filename))
	{
		return false;
	}

	ifstream ifs(filename);
	if (!ifs.is_open())
	{
		return false;
	}

	bool begin_employee = false;
	string line;
	while (getline(ifs, line))
	{
		if (begin_employee)
		{
			stringstream ss(line);
			vector<string> values;
			string value;
			while (getline(ss, value, ';'))
			{
				values.push_back(value);
			}

			salary_employee se;
			if (!se.parse(values))
			{
				return false;
			}
			
			salary_db::instance().add_employee(se);

			continue;
		}
		else
		{
			line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
			if (line == "[employee]")
			{
				begin_employee = true;
				continue;
			}
		}

	}

	return true;
}

bool salary_db::add_employee(const salary_employee& emp)
{
	auto it = employees_.find(emp.id);
	if (it != employees_.end())
	{
		cout << "employee has exist" << endl;
		return false;
	}

	if (emp.id < 0
		|| emp.name.empty()
		|| emp.address.empty()
		|| emp.employee_type_ == employee_type::UNSPECIFIED)
	{
		cout << "paramaters invalid" << endl;
		return false;
	}

	employees_.insert(std::make_pair(emp.id, emp));
	return true;
}

bool salary_db::add_employee(int id, const std::string& name, const std::string& address, employee_type employee_type_)
{
	salary_employee emp;
	emp.id = id;
	emp.name = name;
	emp.address = address;
	emp.employee_type_ = employee_type_;
	emp.create_time = chrono::system_clock::now();
	return add_employee(emp);
}

salary_employee salary_db::get_employee(int id)
{
	auto it = employees_.find(id);
	if (it != employees_.end())
	{
		return it->second;
	}

	return salary_employee();
}

std::vector<salary_employee> salary_db::get_all_employees() const
{
	vector<salary_employee> employees;
	for (const auto& e : employees_)
	{
		employees.push_back(e.second);
	}

	return employees;
}


bool salary_db::has_employee(int id) const
{
	return employees_.find(id) != employees_.end();
}

bool salary_db::change_employee(const salary_employee& emp)
{
	auto it = employees_.find(emp.id);
	if (it == employees_.end())
	{
		cout << "employee not exist id: " << emp.id;
		return false;
	}

	it->second = emp;
	return true;
}

bool salary_db::delete_employee(int id)
{
	auto it = employees_.find(id);
	if (it != employees_.end())
	{
		employees_.erase(it);
		return true;
	}

	cout << "not found employee with id: " << id << endl;
	return false;
}

bool salary_db::add_time_card(const employee_time_card& time_card)
{
	if (time_card.hours <= 0)
	{
		//assert(0);
		cout << "hous mush greater 0" << endl;
		return false;
	}

	auto it = employees_.find(time_card.employee_id);
	if (it != employees_.end())
	{
		if (it->second.employee_type_ != employee_type::HOURLY_WORKER)
		{
			cout << "worker type is not hourly worker, id: " << time_card.employee_id << endl;
			return false;
		}

		time_cards_.push_back(time_card);
		return true;
	}

	cout << "failed to add time_card, user not found, id: " << time_card.employee_id << endl;
	return false;
}

bool salary_db::add_sales_receipt(const sales_receipt& sr)
{
	if (sr.amount <= 0)
	{
		//assert(0);
		cout << "amount mush greater 0, amount: " << sr.amount << endl;
		return false;
	}

	auto it = employees_.find(sr.employee_id);
	if (it == employees_.end())
	{
		cout << "failed to add sales receipt, user not found, id: " << sr.employee_id << endl;
		return false;
	}
	else
	{
		if (it->second.employee_type_ == employee_type::COMMISSIONED_WORKER)
		{
			sales_receipts_.push_back(sr);
			return true;
		}
		else
		{
			cout << "worker type is not hourly worker, id: " << sr.employee_id << endl;
			return false;
		}
	}
}

bool salary_db::add_member(int employee_id, int member_id, int dues)
{
	if (dues <= 0)
	{
		cout << "failed to add emp to society, dues invalid: " << dues << endl;
		return false;
	}

	auto it = employees_.find(employee_id);
	if (it == employees_.end())
	{
		cout << "failed to add emp to society, emp not exist, emp_id: " << employee_id << endl;
		return false;
	}
	else
	{
		auto emp_id = society_members_.find(member_id);
		auto mem_id = society_members_2_.find(employee_id);
		if (emp_id == society_members_.end()
			&& mem_id == society_members_2_.end())
		{
			it->second.society_dues = dues;
			society_members_.insert(make_pair(member_id, employee_id));
			society_members_2_.insert(make_pair(employee_id, member_id));
			return true;
		}
		else
		{
			cout << "member id has bound a employee, member id: " << member_id << endl;
			return false;
		}
	}
}

int salary_db::get_society_dues(int member_id) const
{
	auto it = society_members_.find(member_id);
	if (it == society_members_.end())
	{
		cout << "member not exist, member id: " << member_id << endl;
		return -1;
	}
	else
	{
		auto emp = employees_.find(it->second);
		if (emp == employees_.end())
		{
			cout << "employee not exist, member id: " << member_id;
			return -1;
		}
		else
		{
			return emp->second.society_dues;
		}
	}
}

bool salary_db::service_charge(int member_id, int amount)
{
	auto it = society_members_.find(member_id);
	if (it == society_members_.end())
	{
		cout << "member not exist" << endl;
		return false;
	}
	else
	{
		auto emp = employees_.find(it->second);
		if (emp == employees_.end())
		{
			cout << "emp not exist" << endl;
			return false;
		}
		else
		{
			emp->second.service_amount = amount;
			return true;
		}
	}
}

int salary_db::get_service_amount(int member_id) const
{
	auto it = society_members_.find(member_id);
	if (it == society_members_.end())
	{
		cout << "member not exist" << endl;
		return -1;
	}
	else
	{
		auto emp = employees_.find(it->second);
		if (emp == employees_.end())
		{
			cout << "emp not exist" << endl;
			return -1;
		}
		else
		{
			return emp->second.service_amount;
		}
	}
}

void salary_db::clear()
{
	employees_.clear();
	time_cards_.clear();
	sales_receipts_.clear();
	society_members_.clear();
	society_members_2_.clear();
}