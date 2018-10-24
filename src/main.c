/*
 * Programmer: Henrik A. Christensen     Date Completed: 24-10-2018
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Create a program that calculate the area under a graph between x = a and x = b
 * using the trapexoidal rule:
 *      T = h / 2 * (f(a) + f(b) + 2 * SUM f(xi))     (SUM from i = 1 to n - 1)
 *      h = (b - a) / n
 *      g(x) = x^2 * sin(x)   (a = 0, b = 3.14159)
 *      h(x) = sqrt(4 - x^2)  (a = -2, b = 2)
 *
 * Write a function trap with input parameters a, b, n, and f that implements the trapeziodal rule
 * Call trap with values for n of 2, 4, 8, 16, 32, 64 and 128 on the functions g(x) and h(x)
 *
 * We will assume that f(x) is non-negative in the interval [a,b]
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64) /* if OS is Windows */
#define CLEAR "cls"
#else /* if OS is linux, apple etc... */
#define CLEAR "clear"
#endif

double trap(double a, double b, int n, double (*f)(double x));
double sum(double a, double h, int n, double (*f)(double x));
double g(double x);
double h(double x);
void display_area(double a, double b, double (*f)(double x));

int main(void)
{
  /* clear console */
  system(CLEAR);

  printf("\t===================");
  printf("\n\t Area under graph\n");
  printf("\t===================\n\n");

  printf("\tg(x) = x^2 * sin(x)");
  printf("\n\th(x) = sqrt(4 - x^2)\n");

  printf("\nArea of g(x) from x = 0.0 to x = 3.14159\n");
  printf("----------------------------------------");
  display_area(0.0, 3.14159, g);

  printf("\n\nArea of h(x) from x = -2.0 to x = 2.0\n");
  printf("-------------------------------------");
  display_area(-2.0, 2.0, h);

  printf("\n\n");

  return EXIT_SUCCESS;
}

/*
 * calculate the area under a graph
*/
double trap(double a, double b, int n, double (*f)(double x))
{
  double h = (b - a) / (double) n;

  return (h / 2.0) * (f(a) + f(b) + 2.0 * sum(a, h, n, f));
}

/*
 * calculate the sum from i = 1 to n - 1
*/
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

/*
 * the function g(x)
*/
double g(double x)
{
  return pow(x, 2.0) * sin(x);
}

/*
 * the function h(x)
*/
double h(double x)
{
  return sqrt(4 - pow(x, 2.0));
}

/*
 * outputs to the console the area under a graph with different numbers of intervals
*/
void display_area(double a, double b, double (*f)(double x))
{
  int i;
  int intervals[] = { 2, 4, 8, 16, 32, 64, 128 };
  size_t num_intervals = sizeof(intervals) / sizeof(int);

  for (i = 0; i < num_intervals; i++)
  {
    printf("\nArea with %3d intervals:    %f", intervals[i], trap(a, b, intervals[i], f));
  }
}

