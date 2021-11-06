/*
Anton Ilic
Oct 10th 2021
scrambled.c
Checks if the values in 2 arrays are equal / returns

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define three 3

int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int size)
{
    int i, j, k;
    char a[size];

    if (size == 0) return 1; /*
If size is 0 then scrambled(...) must return 1 (since the arrays have the same - empty -
contents).
*/
    memset(a, 0, size); 

    for(i = 0; i < size; ++i)
    {
        k = 0;
        for( j = 0; j < size; ++j)

        {
            if( arr1[i] == arr2[j] && a[j]==0)
            {
                a[j] = k = 1;
                break;
            }
        }

        if(k == 0)
            return 0;
    }
    return 1;
}
// Bottom is given
int main (void)
{
    unsigned int arr1[] = {10, 15, 20} ;
    unsigned int arr2[]  = {15, 10, 20} ;


    if (scrambled ( arr1, arr2, three) == 1)
    {
        printf("arr2 is a scrambled versiuon of arr1\n");
    }
    else {
        printf("arr2 has different contents to arr1\n");
    }

    return 0;
}



/*
#include <stdio.h>
int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int size ){
    
    printf("\nEnter elements : \n"); 
 
    for(int i=0; i < size; i++) 
    { 
        scanf("%d",&arr1[i]); 
    } 
    for(int j=0;j<size;j++){
		if(arr1[j]!=arr2[j])
			return 1;
	}
	return 0;

    if(scrambled(arr1,arr2,5)==0){
		printf("Arrays have same elements.\n");
	}
	else{
		printf("Arrays have different elements.\n");
	}
		
	return 0;
}
*/
/*
}
int main(){
return 0;
} */


/*
#include <stdio.h>
int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int size );

int main(void){

    int myresult = scrambled(size);
    printf("The result is: %d\n", myresult);

    return 0;
}

*/
/*
int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int size ){
    
   arr1[size] = (1, 2, 3);
   arr2[size] = (1, 2, 3);

    for( unsigned int index = 0; index < size; index++ ) {
      
      if( arr1[index] == arr2[index] ) {
         
      }
      else{
          printf("The arrays aren't equal");
      }

    }

}
*/
