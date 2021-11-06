/*
Made by Anton Ilic on Sept. 26th 2021


*/
#include <stdio.h>

int main(void) {   
    unsigned apples;   
    unsigned bags;
    int applesperbag = 0;
    int remainderapples;
    int i = 1;
    int ctrlChecker=0;
  
    //while (ctrlChecker != EOF){
    //ctrlChecker = scanf("%c", &input);   
    do 
    {
    printf("Please enter the number of apples available: ");  
    scanf("%u", &apples);
    
    printf("Please enter the number of apples each of the bags hold:"); 
    scanf("%u", &bags);
    
    //Could also combind into one statement by a printf statement asking for both and
    //scanf("%u %u", &apples, &bags); but this way looks nicer in terms of UI. 
    applesperbag = apples/bags;
    remainderapples = apples%bags;
    printf("There are %u apple(s) available and %u apple(s) can fit in a bag.\n", apples, bags);    
    printf("There are %u bag(s) of apples and %u apple(s) leftover", applesperbag, remainderapples);
    printf("\n");
    //}
    
    }
    while (i=getchar()!=EOF);

    printf("\nDone.");
    return 0;
}


/*
Write a program that predicts how many whole bags of apples 
can be produced given the number of apples available. ï‚— Prompt the user 
to enter the number of apples available and to enter the number of apples 
each bag holds. ï‚— All bags hold the same amount of apples. ï‚— Echo (i.e., print) 
what the user has just entered, i.e., the number of apples available and the 
number of apples each bag can hold, then display both the number of bags that 
will be produced and the number of apples that will be left over

*/
