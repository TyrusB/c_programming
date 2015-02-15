#include <stdio.h>

// Definitions for our definechar function
#define LOWERCHAR   3
#define UPPERCHAR   2
#define NUMBER      1
#define OTHER       0

#define TRUE        1
#define FALSE       0

#define MAXBUFFER   1000

int definechar(char c);
void printrange(char start, char stop);

int main()
{
  char firstchar, nextchar;
  int firsttype, bufstart, fetched;
  
  bufstart = -1;
  
  printf("Expanding Input:\n");
  while ( (fetched == TRUE && (firstchar=nextchar) && (fetched = FALSE)) || ((firstchar=getchar()) != EOF) ) {
    int firsttype = definechar(firstchar);
    if (firsttype == OTHER) {
      putchar(firstchar);
    } else {
      nextchar = getchar();
      if (nextchar == '-') {
        nextchar = getchar();
        if (definechar(nextchar) == firsttype) {
          printrange(firstchar, nextchar);
        } else {
          putchar(firstchar);
          putchar('-');
          fetched = TRUE;
        }
      } else {
        putchar(firstchar);
        fetched = TRUE;
      }
    }
  }
  printf("\n");
  return 1;
}

int definechar(char c)
{
  if (c>= 'a' && c<='z')
    return LOWERCHAR;
  else if (c>='A' && c<='Z')
    return UPPERCHAR;
  else if (c>='0' && c<='9')
    return NUMBER;
  else
    return OTHER;
}

void printrange(char start, char stop)
{
  while (start <= stop)
    putchar(start++);
}