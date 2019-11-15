#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include "db.cpp"

TEST(AddEmp, SucceedAddOneEmp)
{
	salary_db db;
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_TRUE(db.get_employee(0).name == "lilei");
}

TEST(AddEmp, FailedAddOneEmp)
{
	salary_db db;
	EXPECT_FALSE(db.add_employee(0, "", "addr", employee_type::MONTHLY_WORKER));
}

TEST(AddEmp, AddExistedOneEmp)
{
	salary_db db;
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_FALSE(db.add_employee(0, "aa", "addr", employee_type::MONTHLY_WORKER));
}

TEST(DeleteEmp, DeleteUnexistEmp)
{
	salary_db db;
	EXPECT_FALSE(db.delete_employee(0));
}

TEST(DeleteEmp, DeleteExistedEmp)
{
	salary_db db;
	EXPECT_TRUE(db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER));
	EXPECT_TRUE(db.delete_employee(0));
	EXPECT_TRUE(db.get_employee(0).name == "");
}

TEST(AddTimeCard, AddOneTimeCardToUnexistEmp)
{
	salary_db db;
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_FALSE(db.add_time_card(etc));

}

TEST(AddTimeCard, AddOneTimeCardToExistEmp)
{
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::HOURLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_TRUE(db.add_time_card(etc));
}

TEST(AddTimeCard, AddTwoTimeCardToExistEmp)
{
	salary_db db;
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
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::HOURLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 0;

	EXPECT_FALSE(db.add_time_card(etc));
}

TEST(AddTimeCard, AddTimeCardWorkerTypeInvalid)
{
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER);
	employee_time_card etc;
	etc.employee_id = 0;
	etc.date_time = chrono::system_clock::now();
	etc.hours = 5;
	EXPECT_FALSE(db.add_time_card(etc));
}

TEST(AddSalesReceipt, AddSalesReceiptToNotExistUser)
{
	salary_db db;
	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}

TEST(AddSalesReceipt, AddSalesReceiptToExistUser)
{
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_TRUE(db.add_sales_receipt(sr));
}

TEST(AddSalesReceipt, AddSalesReceiptToWrongUser)
{
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::MONTHLY_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = 1000;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}

// 等数据库有支付日期记录的时候，可以判断当前凭条日期需要在其之后。
//TEST(AddSalesReceipt, OldDateSalesReceipt)
//{
//	salary_db db;
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
	salary_db db;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	sales_receipt sr;
	sr.employee_id = 0;
	sr.date_time = chrono::system_clock::now();
	sr.amount = -100;
	EXPECT_FALSE(db.add_sales_receipt(sr));
}


TEST(AddEmpMember, ToExistEmployee)
{
	salary_db db;
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));
	EXPECT_EQ(dues, db.get_society_dues(0));
}

TEST(AddEmpMember, ToNotExistMember)
{
	salary_db db;
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_FALSE(db.add_member(1, 0, dues));
	EXPECT_EQ(-1, db.get_society_dues(0));
}

TEST(AddEmpMember, MemberBoundEmployee)
{
	salary_db db;
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);
	db.add_employee(1, "zl", "addr", employee_type::HOURLY_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));
	EXPECT_FALSE(db.add_member(1, 0, dues));
	EXPECT_EQ(100, db.get_society_dues(0));
}

TEST(AddEmpMember, InvalidDues)
{
	salary_db db;
	int dues = -1;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_FALSE(db.add_member(0, 0, dues));
}

TEST(ServiceCharge, ToExistMember)
{
	salary_db db;
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));

	int amount = 50;
	EXPECT_TRUE(db.service_charge(0, amount));
	EXPECT_EQ(amount, db.get_service_amount(0));
}

TEST(ServiceCharge, ToNotExistMember)
{
	salary_db db;
	int dues = 100;
	db.add_employee(0, "lilei", "addr", employee_type::COMMISSIONED_WORKER);

	EXPECT_TRUE(db.add_member(0, 0, dues));

	int amount = 50;
	EXPECT_FALSE(db.service_charge(1, amount));
	EXPECT_EQ(-1, db.get_service_amount(1));
}
