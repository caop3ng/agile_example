#pragma once

#include <map>
#include <vector>
#include "db_struct.h"

class salary_db
{
public:
	static salary_db& instance()
	{
		static salary_db db;
		return db;
	}

	bool add_employee(int id, const std::string& name, const std::string& address, employee_type emp_type);
	bool add_employee(const salary_employee& emp);
	salary_employee get_employee(int id);
	bool has_employee(int id) const; // temp
	bool change_employee(const salary_employee& emp);
	bool delete_employee(int id);
	bool add_time_card(const employee_time_card& time_card);
	bool add_sales_receipt(const sales_receipt& sr);
	bool add_member(int employee_id, int member_id, int dues);
	int get_society_dues(int member_id) const;
	bool service_charge(int member_id, int amount);
	int get_service_amount(int member_id) const;
	std::vector<salary_employee> get_all_employees() const;

	void clear();
private:
	salary_db() {};
	salary_db(salary_db&) = delete;

	std::map<int, salary_employee> employees_;
	std::vector<employee_time_card> time_cards_;
	std::vector<sales_receipt> sales_receipts_;
	std::map<int, int> society_members_;
	std::map<int, int> society_members_2_;
};