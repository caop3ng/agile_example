#include "PayrollApplication.h"
#include "TextParserTransactionSource.h"

int main()
{
  TextParserTransactionSource tpts("data.txt");
  Application* app = new PayrollApplication(&tpts);
  app->Excute();
}