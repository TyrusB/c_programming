#include <stdio.h>

int strrindex(char *s, char *t);

int main(int argc, char *argv[])
{
  int ridx;
  
  if (argc == 3) {
    ridx = strrindex(argv[1], argv[2]);
    if (ridx >= 0)
      printf("\nThe second string appears at position %i of the first string, starting from the right.\n", ridx);
    else
      printf("\nThe second string does not appear in the first.\n");
  } else
    printf("\nWrong number of arguments -- takes 2");
  
  return 1;
}

int strrindex(char *s, char *t)
{
  int len, idx, jdx, kdx;
  
  for (len = 0; s[len] != '\0'; len++)
    ;
  
  for (idx = len - 1; idx >= 0; idx--) {
    kdx = idx;
    for (jdx = 0; s[kdx] == t[jdx] && s[kdx] != '\0' && t[jdx] != '\0'; kdx++ && jdx++)
      ;
    
    // String t should be in string s if we're at the end of t AND the last non-ending t char matches s at that position.
    if (t[jdx] == '\0' && t[jdx - 1] == s[kdx - 1])
      return idx;
  }
  
  return -1;
}