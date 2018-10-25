#include <stdlib.h>
#include "CuTest.h"

double stub(double x);

double sum(double a, double h, int n, double (*f)(double x))
{
  int i;
  double sum = 0.0;

  for (i = 1; i <= (n - 1); i++)
  {
    sum += f((double) i * h + a);
  }

  return sum;
}

void TestSum1(CuTest *tc)
{
  double a = 0.0;
  double h = 1.0;
  int n = 2;
  double actual = sum(a, h, n, stub);
  double expected = 1.0;
  CuAssertDblEquals(tc, expected, actual, 0.1);
}

void TestSum2(CuTest *tc)
{
  double a = 0.0;
  double h = 1.0;
  int n = 32;
  double actual = sum(a, h, n, stub);
  double expected = 496.0;
  CuAssertDblEquals(tc, expected, actual, 0.1);
}

void TestSum3(CuTest *tc)
{
  double a = 0.0;
  double h = 1.0;
  int n = 128;
  double actual = sum(a, h, n, stub);
  double expected = 8128.0;
  CuAssertDblEquals(tc, expected, actual, 0.1);
}

CuSuite *SumGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestSum1);
  SUITE_ADD_TEST(suite, TestSum2);
  SUITE_ADD_TEST(suite, TestSum3);
  return suite;
}

double stub(double x)
{
  return x;
}
