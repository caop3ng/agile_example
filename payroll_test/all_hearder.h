#pragma once

#include "Employee.h"
#include "PayrollDatabase.h"
#include "HourlyClassification.h"
#include "TimeCard.h"
#include "ChangeClassificationTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "AddCommissionedEmployee.h"
#include "WeeklySchedule.h"
#include "ChangeSalariedTransaction.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"
#include "ChangeCommissionedTransaction.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"
#include "AddHourlyEmployee.h"
#include "ChangeMethodTransaction.h"
#include "ChangeDirectTransaction.h"
#include "ChangeAffiliationTransaction.h"
#include "ChangeMemberTransaction.h"
#include "UnionAffiliation.h"
#include "ChangeUnaffiliationTransaction.h"
#include "NoAffiliation.h"

extern PayrollDatabase GpayrollDatabase;
extern int MAX_EMP_ID;
