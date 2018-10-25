#include <math.h>
#include <stdlib.h>
#include "CuTest.h"

double g(double x)
{
  return pow(x, 2.0) * sin(x);
}

double h(double x)
{
  return sqrt(4 - pow(x, 2.0));
}

void TestG1(CuTest *tc)
{
  double x = 0.0;
  double actual = g(x);
  double expected = 0.0;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

void TestG2(CuTest *tc)
{
  double x = 1.5708;
  double actual = g(x);
  double expected = 2.4674;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

void TestG3(CuTest *tc)
{
  double x = 3.14159;
  double actual = g(x);
  double expected = 0.0;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

void TestH1(CuTest *tc)
{
  double x = -2.0;
  double actual = h(x);
  double expected = 0;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

void TestH2(CuTest *tc)
{
  double x = 0.0;
  double actual = h(x);
  double expected = 2.0;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

void TestH3(CuTest *tc)
{
  double x = 2.0;
  double actual = h(x);
  double expected = 0.0;
  CuAssertDblEquals(tc, expected, actual, 0.01);
}

CuSuite *GGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestG1);
  SUITE_ADD_TEST(suite, TestG2);
  SUITE_ADD_TEST(suite, TestG3);
  return suite;
}

CuSuite *HGetSuite()
{
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestH1);
  SUITE_ADD_TEST(suite, TestH2);
  SUITE_ADD_TEST(suite, TestH3);
  return suite;
}
