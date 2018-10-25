#include <stdio.h>
#include "CuTest.h"
    
CuSuite *GGetSuite();
CuSuite *HGetSuite();
CuSuite *SumGetSuite();

void RunAllTests(void)
{
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  CuSuiteAddSuite(suite, GGetSuite());
  CuSuiteAddSuite(suite, HGetSuite());
  CuSuiteAddSuite(suite, SumGetSuite());

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}

int main(void)
{
  RunAllTests();
}
