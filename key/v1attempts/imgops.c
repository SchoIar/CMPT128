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

//================================================================================================================
//================================================================================================================
// add lab 8 below

/* 
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers
 * *** file i/o interface (saving into and loading from binary files)***
 * and several utility functions that operate on them.
 *
 * 
 * Do not change this file as your intarr.c will be compiled using it as it is.
*/

/* Keep all the function prototypes you had in Lab 7 
   and add the following 4 function prototypes. 
   Also, copy and paste the modified header comment block above. */

/* Utility function */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
// We have already done this function during our Lecture 25 Flipped Class
// so use it in this lab's intarr.c.

intarr_t* intarr_copy( const intarr_t* ia )
{
    intarr_t *duplicate=malloc(sizeof(intarr_t));
    if (duplicate==NULL)
    {
        return NULL;
    }
    duplicate->len=ia->len;
    duplicate->data=malloc(sizeof(int)*duplicate->len);
    //memcpy(duplicate->data, ia->data, ia->len*sizeof(int));
    int i;
    for (i=0;i<ia->len;i++)
    {
        duplicate->data[i]=ia->data[i];
    }
    return duplicate;
}

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
								unsigned int first, 
								unsigned int last );
	
{
    if (ia == NULL || first > ia->len || last > ia->len || last < first)
    {
        return NULL;
    }
    intarr_t *duplicate_subarray = malloc(sizeof(intarr_t));
    if (duplicate_subarray == NULL)
    {
        return NULL;
    }
    if (first <= last && duplicate_subarray != NULL )
    {
        int i,k = 0,newlen = last-first+1;
        duplicate_subarray->len = newlen;
        duplicate_subarray->data = malloc(sizeof(int)*newlen);
        for (i = first;i <= last;i++)
        {
            duplicate_subarray->data[k] = ia->data[i];
            k++;
        }
        return duplicate_subarray;
    }
    return NULL;    
}	
/* File I/O interface */

// Save the entire array ia into a file called 'filename' in a binary
// file format that can be loaded by intarr_load_binary(). 
// Returns zero on success, or a non-zero error code on failure. 
// Arrays of size 0 should produce an output file containing an empty array.
// Make sure you validate the parameters before you use them.
int intarr_save_binary( intarr_t* ia, const char* filename ){

  if (ia == NULL || filename == NULL){
  return 1; //checks if either are null
}
/*LMAO I have no idea how to do this: watched a few youtube videos and https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
helped a lot
*/
FILE *new=fopen(filename,"w"); //CREATES A NEW FILE
//For writing; if already created earases contents
//and creates a new file

if(fwrite( ia->data, sizeof(int), ia->len, new )==ia->len)
{
  fclose(new);
  return 0;
  //https://www.youtube.com/watch?v=axJREnDphIc
}
  else
{
  fclose(new);
  return 1;
}
}
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)


// Load a new array from the file called 'filename', that was
// previously saved using intarr_save_binary(). 
// Returns a pointer to a newly-allocated intarr_t on success, 
// or NULL on failure.
// Make sure you validate the parameter before you use it.
intarr_t* intarr_load_binary( const char* filename );
