#include <stdio.h>

#define MAX 10000

void escape(char s[], char t[]);
void getinput(char s[]);

int main(int argc, char *argv[]) {
  char s[MAX];
  char t[MAX];
  
  getinput( s );
  escape( s, t);
  
  printf("\nThe escaped String is:\n%s", t);
}

void getinput(char holder[])
{
  char c;
  int i;
  
  for (i = 0; (c = getchar() ) != EOF; i++)
    holder[i] = c;
  
  holder[i] = '\0';
}

void escape(char original[], char copy[])
{
  int origi = 0;
  int copi = 0;
  char c;
  
  while( (c = original[origi++]) != '\0') {
    switch (c) {
      case '\t':
        copy[copi++] = '\\';
        copy[copi++] = 't';
        break;
      case '\n':
        copy[copi++] = '\\';
        copy[copi++] = 'n';
        break;
      default:
        copy[copi++] = c;
    }
  }
  copy[copi++] = '\0';
}