#include <stdio.h>

#define   IN     1
#define   OUT    0

main() {
  int state, c, wl;
  
  int word_lengths[11] = {0}; /* Count all words up to 10 characters, the 11th spot being 'long' words */

  state = OUT;
  wl = 0;
  while ( ( c = getchar() ) != EOF ) {
    if ( c == ' ' || c == '\n' || c == '\t' ) {
      state = OUT;
      if ( wl > 10 ) {
        word_lengths[10] += 1;
      } else if ( wl != 0 ) {
        word_lengths[ wl - 1] += 1;
      }
      wl = 0;
    } else if ( state == OUT ) {
      state = IN;
      wl = 1;
    } else {
      ++wl;
    }
  
  }
  
  printf("\nHistogram of words by length:\n");
  printf("------------\n");
  for ( int i = 0; i < 11; i++ ) {
    /* First Print the number */
    if ( i != 10) {
      printf("%1d:  ", i + 1);
    } else {
      printf("11+: ");
    }
    /* Next a nice visual graph */
    for ( int j = 0; j < word_lengths[i]; j++)
      printf("+");
    printf("\n");
  }
  
}