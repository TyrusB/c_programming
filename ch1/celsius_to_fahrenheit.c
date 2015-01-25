#include <stdio.h>

/* Print a Celsius to Fahrenheit table
  starting at 0, in 20 degree intervals; maxes at 300 */

main() {
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;
  upper = 300;
  step = 20;
  
  celsius = lower;
  
  printf("Celsius\tFahrenheit\n");
  while( celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%3.0f %9.1f\n", celsius, fahr);
    celsius += step;
  }
  
}