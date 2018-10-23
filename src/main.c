/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Coming soon...
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double trap(double a, double b, int n, double (*f)(double x));
double sum(double a, double h, int n, double (*f)(double x));
double g(double x);
double h(double x);

int main(void)
{
  printf("\nG:");
  printf("\nArea: %f", trap(0.0, 3.14159, 2, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 4, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 8, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 16, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 32, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 64, g));
  printf("\nArea: %f", trap(0.0, 3.14159, 128, g));

  printf("\n\nH:");
  printf("\nArea: %f", trap(-2.0, 2.0, 2, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 4, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 8, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 16, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 32, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 64, h));
  printf("\nArea: %f", trap(-2.0, 2.0, 128, h));

  return EXIT_SUCCESS;
}

double trap(double a, double b, int n, double (*f)(double x))
{
  double h = (b - a) / (double) n;

  return (h / 2.0) * (f(a) + f(b) + 2.0 * sum(a, h, n, f));
}

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

double g(double x)
{
  return pow(x, 2.0) * sin(x);
}

double h(double x)
{
  return sqrt(4 - pow(x, 2.0));
}

