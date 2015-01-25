#include <stdio.h>

#define LOWER   -20  /* Lower Limit of table */
#define UPPER   80 /* Upper limit of table */
#define STEP    5  /* step size */

float cels_to_fahr( int celsius );

main() {
  int celsius;
  
  for (celsius = LOWER; celsius <= UPPER; celsius += STEP)
    printf("%3d %6.1f\n", celsius, cels_to_fahr( celsius ) );
}
  
float cels_to_fahr( int celsius ) {
  return (9.0/5.0) * celsius + 32;
}
