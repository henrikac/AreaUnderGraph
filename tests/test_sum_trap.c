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

double trap(double a, double b, int n, double (*f)(double x))
{
  double h = (b - a) / (double) n;

  return (h / 2.0) * (f(a) + f(b) + 2.0 * sum(a, h, n, f));
}

/* SUM TESTS */
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

/* TRAP TESTS */
void TestTrap1(CuTest *tc)
{
  double a = -2.0;
  double b = 2.0;
  int n = 2;
  double actual = trap(a, b, n, stub);
  double expected = 0.0;
  CuAssertDblEquals(tc, expected, actual, 0.1);
}

void TestTrap2(CuTest *tc)
{
  double a = -2.0;
  double b = 2.0;
  int n = 32;
  double actual = trap(a, b, n, stub);
  double expected = 0.0;
  CuAssertDblEquals(tc, expected, actual, 0.1);
}

void TestTrap3(CuTest *tc)
{
  double a = -2.0;
  double b = 2.0;
  int n = 128;
  double actual = trap(a, b, n, stub);
  double expected = 0.0;
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

CuSuite *TrapGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestTrap1);
  SUITE_ADD_TEST(suite, TestTrap2);
  SUITE_ADD_TEST(suite, TestTrap3);
  return suite;
}

double stub(double x)
{
  return x;
}
