#include <stdio.h>

float convert(float fahrenheit);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;   /*lower limit of temperature table*/
  upper = 300; /*upper limit */
  step = 20;   /*step size*/

  fahr = lower;

  printf("Celsius-Fahrenheit table\n"); /* Print heading*/
  while (fahr <= upper)
  {
    printf("%6.1f %10.0f\n", convert(fahr), fahr);
    fahr = fahr + step;
  }
}

/* convert: fahrenheit to celsius*/
float convert(float fahrenheit)
{
  float celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
  return celsius;
}