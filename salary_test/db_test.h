#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include <filesystem>

TEST(AddEmp, SucceedAddOneEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_TRUE(db.get_employee(0).name == "lilei");
}

TEST(AddEmp, FailedAddOneEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	EXPECT_FALSE(db.add_employee(0, "", "addr", employee_type::MONTHLY_WORKER));
}

TEST(AddEmp, AddExistedOneEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_FALSE(db.add_employee(0, "aa", "addr", employee_type::MONTHLY_WORKER));
}

TEST(DeleteEmp, DeleteUnexistEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	EXPECT_FALSE(db.delete_employee(0));
}

TEST(DeleteEmp, DeleteExistedEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_TRUE(db.delete_employee(0));
	EXPECT_TRUE(db.get_employee(0).name == "");
}

TEST(ChangeEmp, ChangeName)
{
	auto& db = salary_db::instance();
	db.clear();

	salary_employee se;
	se.id = 0;
	se.name = "lilei";
	se.address = "addr";
	se.emp_type = employee_type::MONTHLY_WORKER;

	EXPECT_TRUE(db.add_employee(se));
	se.name = "cxx";
	EXPECT_TRUE(db.change_employee(se));

	salary_employee se_not_exist;
	se_not_exist.id = 1;
	se_not_exist.name = "lilei";
	se_not_exist.address = "addr";
	se_not_exist.emp_type = employee_type::MONTHLY_WORKER;

	EXPECT_FALSE(db.change_employee(se_not_exist));
}

TEST(AddTimeCard, AddOneTimeCardToUnexistEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_FALSE(db.add_time_card(etc));

}

TEST(AddTimeCard, AddOneTimeCardToExistEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::HOURLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_TRUE(db.add_time_card(etc));
}

TEST(AddTimeCard, AddTwoTimeCardToExistEmp)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::HOURLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_TRUE(db.add_time_card(etc));

	employee_time_card etc2;
	etc2.employee_id = 0;
	etc2.date_time = chrono::system_clock::now();
	etc2.hours = 8;
	EXPECT_TRUE(db.add_time_card(etc2));
}

TEST(AddTimeCard, AddTimeCardHourInvalid)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::HOURLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 0;

	EXPECT_FALSE(db.add_time_card(etc));
}

TEST(AddTimeCard, AddTimeCardWorkerTypeInvalid)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_FALSE(db.add_time_card(etc));
}

TEST(AddSalesReceipt, AddSalesReceiptToNotExistUser)
{
	auto& db = salary_db::instance();
	db.clear();
	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}

TEST(AddSalesReceipt, AddSalesReceiptToExistUser)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_TRUE(db.add_sales_receipt(sr));
}

TEST(AddSalesReceipt, AddSalesReceiptToWrongUser)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}

//TEST(AddSalesReceipt, OldDateSalesReceipt)
//{
//	auto& db = salary_db::instance();
//	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);
//
//	sales_receipt sr;
//	sr.employee_id = 0;
//	sr.date_time = chrono::system_clock::now();
//	sr.amount = 1000;
//	EXPECT_FALSE(db.add_sales_receipt(sr));
//}

TEST(AddSalesReceipt, InvalidAmount)
{
	auto& db = salary_db::instance();
	db.clear();
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = -100;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}


TEST(AddEmpMember, ToExistEmployee)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));
	EXPECT_EQ(dues, db.get_society_dues(0));
}

TEST(AddEmpMember, ToNotExistMember)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_FALSE(db.add_member(1, 0, dues));
	EXPECT_EQ(-1, db.get_society_dues(0));
}

TEST(AddEmpMember, MemberBoundEmployee)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);
	db.add_employee(1, "zl", "addr", employee_type::HOURLY_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));
	EXPECT_FALSE(db.add_member(1, 0, dues));
	EXPECT_FALSE(db.add_member(0, 1, dues));
	EXPECT_EQ(100, db.get_society_dues(0));
}

TEST(AddEmpMember, InvalidDues)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = -1;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_FALSE(db.add_member(0, 0, dues));
}

TEST(ServiceCharge, ToExistMember)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));

	int amount = 50;
	EXPECT_TRUE(db.service_charge(0, amount));
	EXPECT_EQ(amount, db.get_service_amount(0));
}

TEST(ServiceCharge, ToNotExistMember)
{
	auto& db = salary_db::instance();
	db.clear();
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));

	int amount = 50;
	EXPECT_FALSE(db.service_charge(1, amount));
	EXPECT_EQ(-1, db.get_service_amount(1));
}

TEST(Open, NotExistFile)
{
	auto& db = salary_db::instance();

	string filename = "c:\a.db";
	EXPECT_FALSE(db.open(filename));

	auto a_folder = std::filesystem::temp_directory_path();

	EXPECT_FALSE(db.open(a_folder.string()));
}

//TEST(Open, ExistFile)
//{
//	auto& db = salary_db::instance();
//
//	string filename = "c:\a.db";
//	EXPECT_FALSE(db.open(filename));
//}