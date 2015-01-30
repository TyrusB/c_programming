#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main(int argc, char *argv[])
{
  char *ps;
  char current;
  
  if(argc != 2)
    printf("Wrong number of arguments. Needs exactly one.\n");
  else {
    ps = argv[1];
    
    for (int i = 0; ( current = ps[i] ) != '\0'; ++i) {
      ps[i] = (current <= 'Z' && current >= 'A') ? current - 'A' + 'a' : current;
    }
    
    printf("The lowercase version of your string is %s\n", ps);
  }
  
  return 1;
}
