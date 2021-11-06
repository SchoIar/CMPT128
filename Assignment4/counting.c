/*
Made by Anton Ilic
counting.c
Counts # words/# of lines / # of characters
Oct 19 2021

*/

#include <stdio.h>
int main( )
{

   unsigned long int charCount = 0;
   unsigned long int wordCount = 0;
   unsigned long int lineCount = 1;
   int word = 1; 
   char input;

   do
   {
      charCount += 1; //When a character is input cout of characters goes up

      if (input=='\n')
      {
      lineCount += 1; //when newline is created, line couter is increased vt 1
      word = 1;
      }

      else if ((input>='a' && input<='z')||(input>='A' && input<='Z')||input=='\'')
      { //CHECKS IF BTWN THE INPUT VALUES a, z, A, Z, new line
      
         if (word == 1)
         {
            wordCount += 1;
            word = 0; 
         }
      
      }
         else

         {
            word = 1;
         }
  
   }  
    while((input=getchar())!= EOF ); //LOOPS CHECKING FOR EOF


printf( "%lu %lu %lu\n", charCount, wordCount, lineCount );//PRINTS values

return 0;       

}      
