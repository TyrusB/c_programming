//Psuedocode
// Examine a loop of chars:
//    if it's a start continue looking
//    if the next is '-' continue looking and test the second type
//      else print one and use the second as a start
//    then continue, is the next char a '-'?


#include <stdio.h>

// Definitions for our definechar function
#define LOWERCHAR   3       //'a' - 'z'
#define UPPERCHAR   2       //'A' - 'Z'
#define NUMBER      1       // 1 - 9
#define OTHER       0       // Anything else

#define TRUE        1
#define FALSE       0

// Simple state machine
#define NEEDS_START  0
#define NEEDS_DASH   1
#define NEEDS_END    2
#define OPT_DASH     3
#define OPT_END      4

#define MAXBUFFER   1000

int definechar(char c);           // Returns a constant relating to the type of char the input is
void printrange(char start, char stop);  // Prints a range of characters, inclusive
char getorfetchchar(char *buffer, int *bufend);  //Grabs a character from the given buffer, or from standard input

int main()
{
  char c, startchar, endchar;
  int firsttype, bufend, state, continue_processing;
  char buffer[MAXBUFFER];
  
  bufend = -1;
  buffer[0] = '\0';
  continue_processing = TRUE;
  
  printf("Expanding Input:\n");
  while ( continue_processing == TRUE ) {
    // printf("\n the state is %i\n", state);
    c = getorfetchchar(buffer, &bufend);
    continue_processing = (c == EOF) ? FALSE : TRUE;
    
    switch(state) {
      case NEEDS_START:
        firsttype = definechar(c);
        if (firsttype == OTHER)
          putchar(c);
        else {
          startchar = c;
          state = NEEDS_DASH;
        }
        break;
      case NEEDS_DASH:
        if (c == '-')
          state = NEEDS_END;
        else {
          buffer[++bufend] = c;
          state = NEEDS_START;
        }
        break;
      case NEEDS_END:
        if (definechar(c) != firsttype) {
          putchar(startchar);
          putchar('-');
          state = NEEDS_START;
          buffer[++bufend] = c;
        } else {
          endchar = c;
          state = OPT_DASH;
        }
        break;
      case OPT_DASH:
        if (c == '-') {
          state = OPT_END;
        } else {
          printrange(startchar, endchar);
          state = NEEDS_START;
          buffer[++bufend] = c;
        }
        break;
      case OPT_END:
        if (definechar(c) != firsttype) {
          printrange(startchar, endchar);
          putchar('-');
          state = NEEDS_START;
          buffer[++bufend] = c;
        } else {
          if ((startchar > endchar && endchar > c) || (startchar < endchar && endchar < c)) {
            endchar = c;
            state = OPT_DASH;
          } else {
            printrange(startchar, endchar);
            putchar('-');
            state = NEEDS_START;
            buffer[++bufend] = c;
          }
        }
        break;
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

char getorfetchchar(char *buffer, int *bufend)
{
  char c;
  
  if (*bufend >= 0) {
    c = buffer[0];
    for (int i = 0; i < *bufend; i++)
      buffer[i] = buffer[i + 1];
    
    buffer[(*bufend)--] = '\0';
  } else {
    c = getchar();
  }
  // printf("\n the next char is %c\n", c);
  return c;
}