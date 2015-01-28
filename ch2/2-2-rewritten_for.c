/*
Initial for loop:
for ( i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)

Rewrite it without && or ||
*/


#include <stdio.h>

int main()
{
  int i = 0;
  int c;
  int lim = 100;
  char s[102];
  
  while ( i++ < lim-1 )
    if ( (c = getchar()) != EOF )
      if ( c != '\n')
        s[i] = c;
      else 
        break;
    else
      break;
    
    printf("\nThe line entered was %s\n", s);
}
