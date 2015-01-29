#include <stdio.h>
#include <math.h>

#define MAX_SIZE    100

char[] get_input();
void strip_hex_id( char[] );
int hex_to_int( char[] );
int char_value( char );

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
  int c;
  
  while( ( c = getchar() ) == 'x' || c == 'X' || ( char_value(c) >= 0 && char_val(c) < 16 ) ) {
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

int hex_to_int( char[] s )
{
  char c;
  int total = 0;
  int p = 1;
  
  for( int i = 0; (c = char[i]) != '\0'; ++i) {
    int val = char_val( c );
    total += val * pow(16, p++);
  }
  
  return total;
}

int char_value( int c )
{
  if( c > '0' && c <= '9')
    return c - '0';
  else if( c > 'a' && c <= 'f' )
    return c - 'a' + 10;
  else if( c > 'A' && c <= 'F' )
    return c - 'A' + 10;
  else
    return -1;
}