/* 
 * intarr.c
 *
 * Provides a bounds-checked, resizable array of integers 
 * and several utility functions that operate on them.
 * 
 * Do not change this file as your intarr.c will be compiled using it as it is.

 Made by Bernard Ko and Anton Ilic
 Nov 7th 2021
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

/* Structure type that encapsulates our safe int array. */
//              typedefs removed
/* A type for returning status codes */


// Create a new intarr_t with initial array size "size".
// If successful (i.e. memory allocation succeeds), returns a pointer
// to a newly-allocated intarr_t. 
// If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int size ) {

  // Allocate memory on the heap for struct
  intarr_t *array1 = malloc( sizeof( intarr_t ) );
  if( array1 != NULL ) {

    // Set its field "size"
    array1->size = size;

    // Allocate memory on the heap for array
    array1->data = malloc( size * sizeof(int) );
    if( array1->data == NULL ) {
        free( array1 );
        array1 = NULL;
    }
  }
  return array1;
} // given


// Free all memory allocated for ia. 
// If the pointer is null, do nothing. 
// If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {
  // If heap memory has been allocated for struct ...
  if( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if( ia->data != NULL ) {
      // ... then free it
      free( ia->data );
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia );
    ia = NULL;
  }

  return;
} //given

// Fill the array with "size" random numbers.
void intarr_fill_with_random( intarr_t* ia ) {
  // If heap memory has been allocated for struct ...
  if( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if( ia->data != NULL ) {
      // ... then free it
      free( ia->data );
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia );
    ia = NULL;
  }

  return;
}
// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
                            unsigned int index, 
                            int val )
{
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }
  else if (index < ia->len)
    {
      ia->data[index] = val;
      return INTARR_OK;
    }
  else
  {
    return INTARR_BADINDEX; //if not null nor index < str ptr of structire of len, therefore index
  }
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
                            unsigned int index, 
                            int* val )
{
  if (ia == NULL)
  {
    return INTARR_BADARRAY;
  }
  else if (index < ia->len && val != NULL)
    {
      *val = ia->data[index];
      return INTARR_OK;
    }
    else
    {
      return INTARR_BADINDEX;
    }
}

//====================================anton below is ur code i just commented it for now==========================================

/*

intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){//1
if (ia != NULL)
{
  
  for(int j = 0;j < ia->len;j++)
  {
    if(ia->data[j] == target){
      while (i != NULL){
        *i = j;
        return INTARR_OK;
      }
    }
    return INTARR_NOTFOUND;
  }

}
else{
  return INTARR_BADARRAY;
}
}


intarr_result_t intarr_sort( intarr_t* ia){//2
if (ia != NULL)
{

}
else{
  return INTARR_BADARRAY;
}
}


intarr_result_t intarr_resize( intarr_t* ia, unsigned int newsize ){//#3
  if (ia != NULL){
int i;
int j;//used to store length
j = ia->len;

  }
  else{
    return INTARR_BADARRAY;
  }
}
*/

//==============================================================================

//1
// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
// Pay close attention to the above description as it indicates which 
// of the two algorithms (seen in our lectures) you are to implement.

//2
// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
// Implement whichever sort algorithms we have seen in our lectures. Up to you!
intarr_result_t intarr_sort( intarr_t* ia )
{
    if (ia==NULL)
    {
        return INTARR_BADARRAY;
    }
    else
    {
        int i,k,min,minpos,tmp;
        min=ia->data[0];
        for (i=0;i<ia->len;i++)
        {
            min = ia->data[i];
            for (k=i;k<ia->len;k++)
            {
                if (ia->data[k]<=min)
                {
                    min=ia->data[k];
                    minpos=k;
                }
            }
            tmp=ia->data[i];
            ia->data[i]=min;
            ia->data[minpos]=tmp;
        }
        return INTARR_OK;
    }
}
//3
// Resize ia to contain newsize values. 
// Read: https://en.cppreference.com/w/c/memory/realloc)
// It says: if newsize is less than the original array size, 
// the end of the array is discarded. 
// If newsize is greater than the original array size, the values 
// of the new integers will be undefined. Leave them this way,
// but make sure your test driver calls 
// void intarr_fill_with_random( intarr_t* ia ); 
// right after (if this function is successful) to refill this array.
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.

intarr_result_t intarr_resize( intarr_t* ia, unsigned int newsize )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    int i,original_len;
    //printf("%d",ia->len);
    original_len = ia->len;
    if (newsize >= 0)
    {
        int *new_resize_data = realloc(ia->data,sizeof(int)*newsize);
        ia->len = newsize;
        ia->data = new_resize_data;
        if (new_resize_data)
        {
            //printf("before3\n");
            if (newsize>original_len)
            {
                for (i = original_len;i < newsize;i++)
                {
                    ia->data[i] = 0;
                }
            }
            //printf("before4\n");
        }        
        return INTARR_OK;
    }
    return INTARR_BADALLOC;
}
