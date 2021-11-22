/* 
 * Filename: List.c
 *
 * Description: 
 *
 * Your name: Anton & Bernard
 * Date:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Implements a linked list of integers

 A list is comprised of a single header and zero or more elements. The
 header contains pointers to the first and last elements in the list,
 or NULL if the list is empty. The first element contains a pointer to
 the next element, and so on. The last element in the list has its
 "next" pointer set to NULL.

 ** Global Precondition **

 Functions that operate on an existing list require a valid pointer to
 a list_t header as their first argument.
*/


// Returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.
list_t* list_create( void )
{
  list_t* l = malloc( sizeof(list_t) );
  if( l )
    {
      l->head = NULL;
      l->tail = NULL;
    }
  return l;
}

// Frees all the memory used by the list.
void list_destroy( list_t* list )
{
  element_t* element_1 = list->head;
  while( element_1 )
    {
      element_t* next = element_1->next;
      free( element_1 );
      element_1 = next;
    }      

  free( list );
}

// Returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create( int i )
{
  element_t* el = malloc( sizeof(element_t) );
    el->val = i;
    el->next = NULL;
  return el;
}



// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i )
{
  element_t* el = element_create( i );
  //int result = 0;
  if( list->head == NULL ){
    list->head = el;
  return 1;
  }
  if( list->tail ){
    list->tail->next = el;
  }
  list->tail = el;
  return 0; //return result;
}

// Prepends a new element containing integer i to the front of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i )
{
  element_t* el = element_create( i );

  if( list->tail == NULL ){
    list->tail = el;
    return 1;
  }
	
  if( list->head ){
    el->next = list->head;
  }
  list->head = el;
  
  return 0;
}



// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range
element_t* list_index( list_t* list, unsigned int i )
{
  element_t* el = list->head;
  unsigned int c = 0;
  
  while( c < i )
    {
      if( el->next == NULL ){
	return NULL;
      }
      c++;
      el = el->next;
    }     
	//return result;
  return el;
}



// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list )
{
  printf( "{" );
  element_t* el;
  for( el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}
