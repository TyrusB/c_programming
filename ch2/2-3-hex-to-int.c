#include <stdio.h>

#define MAX_SIZE    100

char[] get_input();
void strip_hex_id( char[] );
int hex_to_int( char[] );

char[MAX_SIZE] hex_string;

int main()
{
  char[] in = get_input();
  strip_hex_id( in );
  int hex = hex_to_int( n );
  
  printf("\nThe value is: %i", hex);
}

char[] get_input()
{
  int i = 0;
  while( ( ( c = getchar() ) > '0' && c <= '9' ) || ( c > 'a' && c <= 'f') || (c > 'A' && c <= 'F') ) {
    hex_string[i++] = c;
  }
  hex_string[i] = '\0';
    
  return hex_string;
}

void strip_hex_id( char[] hex )
{
  int c = char[1];
  if ( c == 'x' || c == 'X' ) {
    for( int i = 2; char[i] != '\0'; ++i)
      char[ i - 2] = char[i];
    char[i-2] = '\0';
  }
}