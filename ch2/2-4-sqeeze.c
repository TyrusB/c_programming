#include <stdio.h>

#define TRUE  1
#define FALSE 0
#define MAX   1000

void squeeze(char s1[], char s2p[]);

int main( int argc, char *argv[] )
{
  char *ps1;
  char *ps2;
  
  if (argc == 1)
    printf("\nThis program requires two command line input values\n");
  else if (argc == 2) {
    ps1 = argv[1];
    printf("Enter a second string to 'squeeze' it from the first.\nString entered:\n%s\n", ps1);
  } else if (argc == 3) {
    ps1 = argv[1];
    ps2 = argv[2];
    printf("Original String:\n%s\nTo Delete:\n%s\n", ps1, ps2);
    squeeze(ps1, ps2);
    printf("Squeezed:\n%s\n", ps1);
  } else
    printf("\nToo many arguments\n");
  
  return 1;
}

void squeeze( char s1[], char s2[] )
{
  int runner;
  int walker;
  int s2m;
  int found;
  
  //Most efficient way to do this would be to load s2 into a hash table, but I dunno how to do that in C yet :-D
  for( runner = 0, walker = 0; s1[runner] != '\0'; ++runner ) {
    found = FALSE;
    for( s2m = 0; s2[s2m] != '\0'; ++s2m)
      if (s2[s2m] == s1[runner]) {
        found = TRUE;
        break;
      }
    
    if( found != TRUE )
      s1[walker++] = s1[runner];
  }
  s1[walker] = '\0';
}