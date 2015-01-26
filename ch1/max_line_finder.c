#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest line of input */
main() {
  int len;
  int max;
  char line[MAXLINE];     /* The current input line */
  char longest[MAXLINE];  /* longest line seen so far */
  
  max = 0;
  while ( (len = getline(line, MAXLINE)) > 0 ) {
    if ( len > max ) {
      max = len;
      copy( longest, line );
    }
  }
  if ( max > 0 )
    printf("%s", longest);
  return 0;
}

/* Read a line of into the inputted argument 's' and return the length */
int getline(char s[], int lim)
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