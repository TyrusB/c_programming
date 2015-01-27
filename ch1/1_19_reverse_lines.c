#include <stdio.h>

#define MAX   1000

int reverse(char s[]);
int tgetline(char s[], int lim);

int main()
{
  int len;
  char line[MAX];
  
  while( (len = tgetline(line, MAX)) > 0 ) {
    reverse( line );
    printf("%s", line);
  }
}

int reverse(char s[])
{
  int i, j, temp;
  
  for( i = 0; s[i] !='\0'; ++i )
    ;
  
  --i; // Jump back one char before the end
  for( j = 0; j <= (i / 2); ++j ) {
    temp = s[j];
    s[j] = s[i - j];
    s[i-j] = temp;
  }
  
  return i;
}

int tgetline(char s[], int lim)
{
  int c, i;
  
  for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
