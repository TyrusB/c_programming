#include <stdio.h>

#define   IN     1
#define   OUT    0

main() {
  int nc, nl, nw, state, c;

  state = OUT;
  nc = nl = nw = 0;
  while ( ( c = getchar() ) != EOF ) {
    ++nc;
    if ( c == '\n' )
      ++nl;
    if ( c == ' ' || c == '\n' || c == '\t' ) {
      state = OUT;
    } else if ( state == OUT ) {
      state = IN;
      ++nw;
    }
  
  }
  
  printf("Words\tLines\tCharacters\n");
  printf("%3d %8d %8d\n", nw, nl, nc);
  
}