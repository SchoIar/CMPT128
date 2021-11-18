#include "point_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main()
{
	int i;
	point_array_t* pa = malloc(sizeof(point_array_t));
	pa->len = 0;
	pa->reserved = 0;
	pa->points = malloc(sizeof(point_t)*pa->reserved);
	//for( i = 0; i < pa->len; ++i)
		//point_array_remove( pa, i);

	point_array_init( pa );
	printf("%zu\n",pa->len);

	point_t* pn=malloc(sizeof(point_t));
	pn->x=10;
	pn->y=8;
	pn->z=9;
	point_array_append( pa, pn );
	printf("%zu   %zu  %f  %f\n",pa->len,pa->reserved,pa->points[0].x,pa->points[1].x);
	
	for (i=0;i<99;i++)
	{
		point_array_append( pa, pn );
	}
	printf("%zu   %zu  %f  %f\n",pa->len,pa->reserved,pa->points[0].x,pa->points[1].x);
	point_array_remove( pa, 1);
	printf("%zu   %zu  %f\n",pa->len,pa->reserved,pa->points[1].x);
	point_array_remove( pa, 100);
	printf("%zu   %zu  %f\n",pa->len,pa->reserved,pa->points[100].x);
	//point_array_reset( pa );
	//printf("%zu   %zu  \n",pa->len,pa->reserved);

	return 0;


}
