#include <stdio.h>

// Definitions for our definechar function
#define LOWERCHAR   3       //'a' - 'z'
#define UPPERCHAR   2       //'A' - 'Z'
#define NUMBER      1       // 1 - 9
#define OTHER       0       // Anything else

#define TRUE        1
#define FALSE       0


int definechar(char c);           // Returns a constant relating to the type of char the input is
void printrange(char start, char stop);  // Prints a range of characters, inclusive

int main()
{
  char firstchar, nextchar;
  int firsttype, fetched;
  
  printf("Expanding Input:\n");
  while ( (fetched == TRUE && (firstchar=nextchar) != EOF) || ((firstchar=getchar()) != EOF) ) {
    fetched = FALSE;
    firsttype = definechar(firstchar);
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
      } else { // if the next char is not '-'
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
  if (start < stop)
    while (start <= stop)
      putchar(start++);
  else
    while (start >= stop)
      putchar(start--);
}