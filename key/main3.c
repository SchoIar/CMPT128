#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
int main()
{
	int i;
	intarr_t a;
	a.len=2;

	a.data=malloc(sizeof(int)*a.len);
	for(i=0;i<a.len;++i)
		a.data[i]=10;
	intarr_save_json( &a, "a.txt");
	intarr_load_json( "a.txt");
	return 0;

	/*FILE * file;
    int count=0;
    char ch;
    int k,i=0;
    intarr_t *new=malloc(sizeof(intarr_t));
 
    
    file = fopen ("file.txt", "r+");
    fputs("[ 111,\n 2,\n 3, 4, 5 ]", file);
    rewind(file);
 
    fseek(file,0,SEEK_SET);
    while (!feof(file))    // count number of elements
    {
        ch = getc(file);
        if (ch == ','){
            count ++;
        }
    }
    //printf("%d@",count);
    
    //int array[count+1];
    //Consider if count=0;
    if (count==0)
    {
        new->len = 0;
        new->data = NULL;
        return 1;
    }
    new->len=count+1;
    new->data=malloc(sizeof(int)*new->len);
    fseek(file,0,SEEK_SET);
    while(i<=count)
    {
        while (fscanf(file, "%d",&k)!=1)
        {
        fseek(file, 1, SEEK_CUR);
 
        }
        //printf("!!%d\n",k);
        new->data[i]=k;
        
        i++;
    }
    //printf("%d!!\n",new->len);
    fseek(file,0,SEEK_END);
    fclose(file);
    int u=0;
    for(u=0;u<new->len;u++)
    {
    	printf("@%d\n",new->data[u]);
    }
 
    return(0);*/
}

/*int main()
{
	intarr_t* new = malloc(sizeof(intarr_t));
    if (new)
    {
        new->data = malloc(sizeof(int)*6);
        new->len = 6;
    }
    char filename[8]="file.txt";
    intarr_save_json( new, filename );
    intarr_t* iia=malloc(sizeof(intarr_t));
    iia=intarr_load_json( filename );
    printf("%d@@",iia->data[1]);
    return 0;
}*/
