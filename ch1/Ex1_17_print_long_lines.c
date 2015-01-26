#include <stdio.h>
#define   MAXLINE         1000
#define   LONG_DEF        80

int getlinelen(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest line of input */
main() {
  int len;
  int max;
  char line[MAXLINE];     /* The current input line */
  
  max = 0;
  while ( (len = getlinelen(line, MAXLINE)) > 0 ) {
    if ( len > LONG_DEF ) {
      printf("Long Line:\n");
      printf("%s \n", line);
    }
  }
  return 0;
}

/* Read a line of into the inputted argument 's' and return the length */
int getlinelen(char s[], int lim)
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

/* copy 'from' into 'to' */
void copy(char to[], char from[])
{
  int i;
  
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}