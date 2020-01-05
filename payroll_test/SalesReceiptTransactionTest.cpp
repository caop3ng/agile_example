#include <gtest/gtest.h>
#include "all_hearder.h"

#include "AddCommissionedEmployee.h"
#include "SalesReceiptTransaction.h"
#include "CommissionedClassification.h"
#include "SalesReceipt.h"

TEST(Payroll, AddSalesReceipt)
{
  int empId = 5;
  AddCommissionedEmployee t(empId, "Bill", "Home", 1000, 3);
  t.Execute();

  SalesReceiptTransaction srt(Date(10, 31, 2001), 200, empId);
  srt.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);

  auto pc = e->GetClassification();
  auto cc = dynamic_cast<CommissionedClassification*>(pc);
  EXPECT_TRUE(cc != nullptr);

  auto sr = cc->GetSalesReceipt(Date(10, 31, 2001));
  EXPECT_TRUE(sr != nullptr);
  EXPECT_EQ(200, sr->GetAmount());
}