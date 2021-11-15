#include <stdio.h>
#include "intarr.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //task 1
    printf("TASK 1\n");
    intarr_t* new = intarr_create(5);
    printf("%d\n",new->len);
    //task 2
    printf("TASK 2\n");
    intarr_set(new,0,9);
    printf("%d\n",new->data[0]);
    //    bool cond = (new->data[1]==NULL);
    //printf("%d\n",new->data[0]==0);
    int i = 2;
    printf("%d\n",i);
    intarr_get(new,1,&i);
    printf("%d\n",i);
    //task 3
    // new = 96483
    intarr_set(new,1,6);
    intarr_set(new,2,4);
    intarr_set(new,3,8);
    intarr_set(new,4,3);
    intarr_t* new_copy= intarr_copy( new );
    printf("TASK 3 \n");
    printf("%d\n",new_copy->len);
    int iter;
    for(iter=0; iter<5; iter++){
        printf("%d ",new_copy->data[iter]);
    }
    printf("\n");
    //task 4
    // new = 96483
    // after sort, 34689
    printf("TASK 4\n");
    //intarr_set(new,1,6);
    //intarr_set(new,2,4);
    //intarr_set(new,3,8);
    //intarr_set(new,4,3);
    
    for(iter=0; iter<5; iter++){
        printf("%d",new->data[iter]);
    }
    intarr_sort( new );
    for(iter=0; iter<5; iter++){
        printf("%d",new->data[iter]);
    }
    printf("\n");
    //task 5
    //new = 34689
    //after found 34689
    //new i = 2 (location index
    int w = 5;
    printf("TASK 5\n");
    intarr_find( new, 6, &w );
    for(iter=0; iter<5; iter++){
        printf("%d",new->data[iter]);
    }
    
    printf("\n");
    // task 6a
    // NEW = 34689
    // ADD 1
    // 346891
    printf("TASK 6a\n");
    intarr_push( new, 7 );
    int ss=0;
    for(ss=0;ss<100;ss++)
    {
        intarr_push( new, 7 );
    }
    for(iter=0; iter<new->len; iter++){
        printf("%d",new->data[iter]);
    }
    printf("\n");
    // task 6b
    // new = 346897
    // pop 7
    // return 346890
    intarr_set(new,3,0);
    // new 3460897
    printf("TASK 6b\n");
    int t6b = -1;
    intarr_pop( new, &t6b );
    for(iter=0; iter<new->len; iter++){
        printf("%d",new->data[iter]);
    }
    printf("\n");
    intarr_pop( new, &t6b );
    for(iter=0; iter<new->len; iter++){
        printf("%d",new->data[iter]);
    }
    printf("\n");
    

    printf("new t6b %d",t6b);
    printf("\n");
    
    //task 7
    // new = 34689 size=6
    // after resize (newlen=8)  new=34689000
    // after resize (newlen=4)  new=3468
    // after resize (newlen=6)  new=346890
    
    printf("TASK 7\n");
    //intarr_resize( new, 8 );
    intarr_resize( new, 15 );
    for(iter=0; iter<new->len; iter++){
        printf("%d",new->data[iter]);
    }
    printf("new resize array\n");
    intarr_resize( new, 10);
    for(iter=0; iter<new->len; iter++){
        printf("%d",new->data[iter]);
    }
    
    printf("new resize array2\n");
    
    //task 8
    //new = 346890
    //first 1 ; last 3 ; subarray_copy = 468
    //
    printf("TASK 8\n");
    intarr_t *subarray_copy=intarr_copy_subarray( new , 1 , 4);
    int m;
    for (m=0;m<subarray_copy->len;m++)
    {
        printf("%d ",subarray_copy->data[m]);
    }
    printf("\n");
    /*printf("Lab6\n");
    printf("task 1 \n");
    char filename[11]="myfiel.txt";
    printf("1\n");
    intarr_save_binary( subarray_copy, filename );
    printf("2\n");
    intarr_t *gett=intarr_load_binary( filename );
    printf("3\n");
    printf("%d",gett->len);*/

    return 0;
}
