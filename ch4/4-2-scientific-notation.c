//This exercise asks us to extend a basic custom atof function that takes a string and converts it to a floating point value. The function should take an input in the form 123.456e-7 and conver it to scientific notation.

#include <stdio.h>
#include <ctype.h>

double atof(char *s);

int main(int argc, char *argv[])
{
  if (argc != 2)
    printf("\nWrong number of args: this function requires 1");
  else
    printf("\nThe value of your number is: %f\n", atof(argv[1]));
  
  return 1;
}

double atof(char *s)
{
  double val, power, expval, exppower;
  int i, sign, expsign;
  
  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if(s[i] == 'e' || s[i] == 'E') {
    i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    expval = atof(&s[i]);
    exppower = 1.0;
    for (int i = 0; i < expval; i++ )
      exppower *= 10.0;
    
    power = (expsign == -1) ? power * exppower : power / exppower;
  }
  
  return sign * val / power;
}