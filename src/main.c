/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Coming soon...
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

double trap(double a, double b, int n, double (*f)(double x));
double sum(double a, double h, int n, double (*f)(double x));
double g(double x);
double h(double x);
void display_output(double a, double b, double (*f)(double x));

int main(void)
{
  /* clear console */
  system(CLEAR);

  printf("===================");
  printf("\n Area under graph\n");
  printf("===================\n\n");

  printf("\nArea of g(x) from x = 0.0 to x = 3.14159\n");
  printf("----------------------------------------");
  display_output(0.0, 3.14159, g);

  printf("\n\nArea of h(x) from x = -2.0 to x = 2.0\n");
  printf("-------------------------------------");
  display_output(-2.0, 2.0, h);

  printf("\n\n");

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

void display_output(double a, double b, double (*f)(double x))
{
  int i;
  int slides[] = { 2, 4, 8, 16, 32, 64, 128 };
  size_t num_slides = sizeof(slides) / sizeof(int);

  for (i = 0; i < num_slides; i++)
  {
    printf("\nArea: %f", trap(a, b, slides[i], f));
  }
}

