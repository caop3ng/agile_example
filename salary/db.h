#pragma once

#include <map>
#include <vector>
#include "db_struct.h"

class salary_db
{
public:
	bool add_employee(int id, const std::string& name, const std::string& address, employee_type emp_type);
	salary_employee get_employee(int id);
	bool delete_employee(int id);
	bool add_time_card(const employee_time_card& time_card);
	bool add_sales_receipt(const sales_receipt& sr);
	bool add_member(int employee_id, int member_id, int dues);
	int get_society_dues(int member_id) const;
	bool service_charge(int member_id, int amount);
	int get_service_amount(int member_id) const;
private:
	std::map<int, salary_employee> employees_;
	std::vector<employee_time_card> time_cards_;
	std::vector<sales_receipt> sales_receipts_;
	std::map<int, int> society_members_;
};