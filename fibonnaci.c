#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int n = 10;
    int i;
    int* a = (int *)malloc(sizeof(int)*n);
    memset(a, 0, n);
    a[0] = 1;
    a[1] = 1;
    for (i = 2; i<=n; i++)
    {
	a[i] = a[i-1] + a[i-2];
    }
    for (i=0; i<n ; i++)
    {
	printf("----fibonacci a[%d]=%d \r\n",i,a[i]);
    }
    return;
}
	
