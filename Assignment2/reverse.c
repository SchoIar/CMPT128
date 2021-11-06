
/*
Desc: Asks for (10) ints & echos them, then prints them backwords
Name of file: reverse.c
Date: Oct 4rth, 2021
Made by: Anton Ilic

Please note: this does NOT reverse the array in place; as such recieved a lower mark then possible.
*/
#include <stdio.h>
 
int main() {
 const int ten = 10; //can modify to modify # of inputs needed
 int tenNumbers[ten];

 printf("Please, enter %d integers then press Enter: ", ten);
 
 for(int i = 0; i < ten; ++i) {
    scanf("%d", &tenNumbers[i]);
 }
 
 printf("Content of array before reversing: ");
 
 for(int y = 0; y < ten; ++y){
    printf("%d ", tenNumbers[y]);
 }
  printf("\nContent of array after reversing: ");
 for(int z = ten - 1; z >= 0; --z){
     printf("%d ", tenNumbers[z]);
 }
  return 0;
}

// Made by Anton Ilic, Sept 30th 2021; updated on Oct 1st due to in class
// grading script being implimented
// filename, desc, date, author
