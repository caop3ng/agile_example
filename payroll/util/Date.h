#pragma once

class Date
{
public:
  Date(int month, int day, int year);

  bool Equal(Date& other) const;

private:
  int itsMonth{ -1 };
  int itsDay{ -1 };
  int itsYear{ -1 };
};

