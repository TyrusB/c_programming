#include <stdio.h>

/* This function returns the 0-indexed position of the first occurance in string 1 of a character from string 2 */
int mfind(char s1[], char s2[]);

int main(int argc, char *argv[])
{
  char *ps1;
  char *ps2;
  int idx;
  
  if(argc != 3)
    printf("Please enter exactly two arguments\n");
  else {
    ps1 = argv[1];
    ps2 = argv[2];
    
    idx = mfind(ps1, ps2);
    if (idx == -1)
      printf("No occurances of letters in the second input found.\n");
    else
      printf("The first occurance of a letter from the second string occuring in the first was at letter %i\n", (idx + 1));
  }
  
  return 0;
}

int mfind(char s1[], char s2[])
{
  for( int i = 0; s1[i] != '\0'; ++i )
    for( int j = 0; s2[j] != '\0'; ++j )
      if (s1[i] == s2[j])
        return i;
  
  return -1;
}