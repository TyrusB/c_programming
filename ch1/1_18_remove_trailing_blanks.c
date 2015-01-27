#include <stdio.h>
#define   MAXLINE         10000

int getlinelen(char line[], int maxline);
int striptabs(char line[]);

/* remove trailing tabs from line */
main() {
  int len, lastchar;
  char line[MAXLINE];     /* The current input line */
  
  while ( (len = getlinelen(line, MAXLINE)) > 0 ) {
    if ( striptabs(line) > 0)
      printf("%s", line);
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

int striptabs(char s[])
{
  int i;
  
  for( i = 0; s[i] != "\0"; i++ )
    ;
  
  --i;
  for( i > 0; (s[i] == "\t") || (s[i] == " "); i-- )
    ;
  
  if( i > 0 ) {
    ++i;
    s[i] = "\n";
    ++i;
    s[i] = "\0";
  }
  
  return i;
}