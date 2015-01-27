#include <stdio.h>

#define TAB_STOPS         15      /* Tab stops every so many spaces */
#define MAXIMUM           10000   /* Max size of the input */

int main()
{
  int c, i;
  char output[MAXIMUM];
  int seen = 0;
  
  while( (c = getchar()) != EOF ) {
    if ( c == '\t' )
      for( i = 0; i < ( TAB_STOPS - ( seen % TAB_STOPS ) ); ++i, output[seen++] = 'x') /* using 'x' for testing */
        ;
    else 
      output[seen++] = c;
  }
  
  output[++seen] = '\0';
  printf("%s", output);
}
