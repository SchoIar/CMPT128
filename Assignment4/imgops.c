/*
 * Filename: imgops.c
 *
 * Description: Simple operations on images
 *
 * Author: RV
 * Modified by: AL
 *
 * Completed by: Anton Ilic
 * Completion Date: Oct27 2021
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

/* Get the value in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

/* Set the pixel at coordinate {x,y} to the specified color. */
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 


/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
    // Put your code here.
    memset( array, 0, cols * rows * sizeof(array[0]) );
    //maybe use memset?
     /*
unction void *memset(void *str, int c, size_t n) c
opies the character c (an unsigned char) to the first 
n characters of the string pointed to, by the argument str.

 */
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
	// Put your code here
	 int i;

  uint8_t* a = malloc( sizeof(uint8_t)*cols*rows);
  
  if (a == NULL)
  {
    return NULL;//if a is null return null
  }
  
  else 
  {
    for (i=0; i <cols*rows; i++)//checks thru the array
    {
      a[i]=array[i];
    }

    return a;
  }

}


/* Return the darkest color that appears in the array; 
   i.e. the smallest value.
*/
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	// Put your code here
	int i;

  uint8_t minimum = array[0];

  for (i=0;i < cols*rows;i++)
  {

    if (array[i] <= minimum)
    {
      minimum = array[i]; //checks if smlr then max ELSE sets to min
    } 
        
  }
  return minimum;//returns the minimum value
}


/* Return the lightest color that appears in the array; 
   i.e. the largest value.
*/
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
	// Put your code here
	int i;

  uint8_t maximum = 0;
  
  for (i=0;i < cols*rows;i++)
  {
    if (array[i] >= maximum) //checks if greater then max ELSE sets to max
    {
      maximum = array[i];
    } 
        
  }
  return maximum;//returns the max value
}



/* Replace every instance of pre_color with post_color. */
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
	// Put your code here
  
	int i;

  for (i=0;i<cols*rows;i++)//checks thru the array 
    {
    if (array[i]==pre_color) //if its equal to precolor
    {
        array[i]=post_color; //replaces w/ post color
     }
    }
    
} 


/* Flip the image, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
    // Put your code here
    return;
}

/* Find the first coordinate of the first pixel with a value that
   equals color. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // Put your code here
    return 0;
}

/* Invert the image, so that black becomes white and vice
   versa, and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // Put your code here
	int i;
  int j;

  for (i=0; i<rows; i++)//checks thru the rows
  {

    for (j=0; j<cols; j++) // in each row checks thru the collums
    {
      array[i*cols+j] = 255-array[i*cols+j];
    }

  }

  //return 0;
}
