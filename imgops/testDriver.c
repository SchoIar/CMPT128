/* Header comment block 

 gcc -o td testDriver.c intarr.c 

*/

#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h> 

#include "intarr.h"

void print_intarr(intarr_t* ia) {
	
  if (ia != NULL ) {
    printf("Printing intarr of length %d:\n", ia->size);
    for( unsigned int i=0; i < ia->size; i++ )
      printf( "%d ", ia->data[i] );
    puts( "(end)" );
  }
  
  return;
}

int main( int argc, char* argv[] ) {

  printf("Creating test_ia\n"); 
  intarr_t* test_ia = intarr_create( 10 );
  if ( test_ia ==  NULL ) {
    printf("test_ia ==  NULL\n");
    return 1;
  } 

  printf("Populating test_ia\n");
  // Put random data in the array
  intarr_fill_with_random( test_ia );

  printf("Printing test_ia\n"); 
  print_intarr( test_ia );

  printf("Destroy test_ia\n");  
  intarr_destroy( test_ia );
  
  return 0;
}
