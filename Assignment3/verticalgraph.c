
/*
By Anton Ilic
Oct 10th 2021
verticalGraph.c
Prints out a vertical histogram based on user input
*/

#include <stdio.h>
int main( void )
{
int n = 0; //number'd input
int numbers[80];
int max = -1;


printf( "Enter integer(s): " );

do{ //Stores # of inputs untill EOF is reached OR 
    if( numbers[n] > max ){
        max = numbers[n];
    }
    ++n;
    
} while(scanf( "%d", numbers + n) != EOF );
printf("\n");

for(max; max > 0; --max) {
    for( int i = 0; i < n; ++i){
        
        if(numbers[i] >= max){ //if the input is a number there print
        printf( "#" );
        }
        else{
            printf(" "); 
        }
    }
    printf( "\n" );
}

printf( "\nDone" );

return 0;
}

/**
 

By Anton Ilic
Oct 10th 2021
verticalGraph.c
user inputs # of values & values then it prints out a vertical histogram 


#include <stdio.h>
#define zero 0

void histogramify(int numbers[], int length, int n) {//in this case fxn uses 
//the array, the array's length and 0 
	int finished = 1; 

	for(int i = 0; i < length; ++i){ 

        if((numbers[i] - n) > zero) // checks if all #s are 
			finished = zero;
    }

//not sure if im allowed to use this type of statement
		//return;
    
    if (finished == zero){
		
		histogramify(numbers, length, n + 1); 
		
	
		for(int i = 0; i < length; ++i) {
			
			int number = numbers[i] - n; // specific @
			if(number <= zero) 
				printf(" ");
			else
				printf("#");// may include a space BTWN inputs for better UI/output (would also need a space for #1)
 		}
    }
		printf("\n");//without this; would be doing a Horizontal Histogram;
	
}

int main(void) {
    
int i = zero;
int ArraySize = zero;


 do {
    printf("Enter number of inputs: "); 
    scanf("%d",&ArraySize);
    
    int numbers[ArraySize];//user selects size of the array.
    
     printf("Enter input value(s): ");
     for(i = 0; i < ArraySize;  i++){
        scanf("%d", &numbers[i]);
     }

	int length = sizeof(numbers) / sizeof(int);
	histogramify(numbers, length, zero);

    }
    while (i=getchar()!=EOF); //CHECKS EOF
    
    return 0;
}
**//////
