#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int intarr_save_binary( intarr_t* ia, const char* filename )
{
    if (ia==NULL) 
    {
        return 1;
    }
    if (filename==NULL)
    {
        return 1;
    }
    
    //return 0 if success;
    FILE *new=fopen(filename,"w");
    if(fwrite( ia->data, sizeof(int), ia->len, new )==ia->len)
    {
        fclose( new );
        return 0;
    }
    else{
        fclose( new );
        return 1;
    }
    
    
}

intarr_t*  intarr_load_binary( const char* filename )
{
    if (filename==NULL)
    {
        return NULL;
    }
    FILE *file = fopen( filename ,"r");
    if (file==NULL)
    {
        return NULL;
    }
    fseek(file,0,SEEK_END);
    int size;
    size=ftell(file)/sizeof(int);
    printf("%d\n",size);
    fseek(file,0,SEEK_SET);
    //printf("11\n");
    intarr_t *arr=malloc(sizeof(intarr_t));
    arr->len=size;
    //printf("22\n");
    arr->data=malloc(sizeof(int)*arr->len);
    //printf("33\n");
    int rlen=fread(arr->data, sizeof(int), size, file);
    if(rlen==arr->len)
    {
        //printf("44\n");
        fclose( file );
        return arr;
    }
    
    else{
        fclose( file );
        return NULL;
        
    }   
}

