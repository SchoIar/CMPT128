/*
                                    //.... sizeof(int);
#include <stdio.h>
int main(void)
{
      int x = 10;
      int y = 10;
      int myprefix = ++x;
      int mypostfix = y++;
      printf("The prefix result: %d, the postfix result: %d\n", myprefix,
      mypostfix);
      
      int arr[3] = {1, 2, 3};
      size_t arrsize = sizeof(arr);
      printf("Total array size in bytes: %ld\n", arrsize);
//sizeif prints the size of the array

}//PRINTS "11" then "10"
*/

/*
                                    //DECLAIRING A POINTER: some_type* pointer_name;

#include <stdio.h>
int main(void)
{
      int arr[5] = {10, 20, 30, 40, 50};
      int *p = arr; /* p now points at the first array element */
      printf("The first array element is: %d\n", *p);
}
*/
      
/*
                                                      //functions
#include <stdio.h>
int mySum(int x, int y)
{
return x + y; }
int main(void)
{
      int myresult = mySum(10, 20);
      printf("The result is: %d\n", myresult);
}

*/
  
/*

A structure is also a type. The name of this type is the name of the structure. A structure is a collection of variables, an excellent way to group the variables and organize data.
Let us write a simple example that declares a structure with three members

*/
/*
#include <stdio.h>
typedef struct
{
      char c;
      int x;
      double d;
} MyStruct;
int main(void)
{
      MyStruct s = {'a', 123, 456.789};
      printf("Variable s of type MyStruct initialized.\n");
      printf("Member c has a value of %c\n", s.c);
      printf("Member x has a value of %d\n", s.x);
      printf("Member d has a value of %f\n", s.d);
}

*/
  
      
/*
#include <stdio.h>

int main(void)
{

    char *p = "Hello";
    printf("%c", *p);
//PRINTS OUT JUST H

      char* x = "Hello World!";
      printf("%s", x);
//PRINTS OUT ALL 

  
}




*/
      
