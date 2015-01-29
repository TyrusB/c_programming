#include <stdio.h>
#include <math.h>

#define MAX_SIZE    100

void get_input( char s[]);
void strip_hex_id( char hex_sting[] );
int hex_to_int( char hex[] );
int mchar_value( char c);

char hex_string[MAX_SIZE];

int main()
{
  get_input( hex_string);
  strip_hex_id( hex_string );
  int hex = hex_to_int( hex_string );
  
  printf("\nThe value is: %i\n", hex);
}

void get_input( char s[] )
{
  int i = 0;
  char c;
  
  while( ( c = getchar() ) == 'x' || c == 'X' || ( mchar_value(c) >= 0 && mchar_value(c) < 16 ) ) {
    s[i++] = c;
  }
  s[i] = '\0';
}

void strip_hex_id( char hex[] )
{
  int c = hex[1];
  int i;
  
  if ( c == 'x' || c == 'X' ) {
    for( i = 2; hex[i] != '\0'; ++i)
      hex[ i - 2] = hex[i];
    hex[i-2] = '\0';
  }
}

int hex_to_int( char s[] )
{
  char c;
  int total = 0;
  int p = 0;
  int i = 0;
  
  while( s[i] != '\0' )
    ++i;
  --i;
  
  for( ; i >= 0; i--) {
    int val = mchar_value( s[i] );
    total += val * pow(16, p++);
  }
  
  return total;
}


int mchar_value( char c )
{
  if( c > '0' && c <= '9')
    return c - '0';
  else if( c >= 'a' && c <= 'f' )
    return c - 'a' + 10;
  else if( c >= 'A' && c <= 'F' )
    return c - 'A' + 10;
  else
    return -1;
}