#pragma once

#include <string>
#include <vector>

enum class Command
{
	kUnknown = 0,
	kList,
	kAdd,
	kChange,
	kHelp,
	kExit,
	kClear,
	kTimeCard,
	kSalesReceipt,
	kServiceCharge,
	kChgEmp,
	kChgEmpName,
};

enum class EmployeeProperties
{
	kUnknown = 0,
	kName = 1,
	kAddress = 2,
	EmployeeProperties_MAX = kAddress,
};

inline EmployeeProperties& operator++(EmployeeProperties& p)
{
	return p = static_cast<EmployeeProperties>(static_cast<int>(p) + 1);
}

inline bool operator<(EmployeeProperties& a, EmployeeProperties& b)
{
	return static_cast<int>(a) < static_cast<int>(b);
}

class command_line
{
public:
	command_line();

	Command parse(const std::string& text) const;
	bool exec_command(Command cmd) const;

private:

	bool exec_help() const;
	bool exec_list() const;
	bool exec_add() const;
	bool exec_clear() const;
	bool exec_time_card() const;
	bool exec_sales_receipt() const;
	bool exec_service_charge() const;
	bool exec_chg_emp() const;

	bool exec_chg_emp_name() const;
	bool exec_chg_emp_address() const;
};