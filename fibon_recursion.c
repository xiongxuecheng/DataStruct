#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int fibona(int n)
{
    int ret = 0;
    if ( n == 1 || n == 2 )
	return 1;
    else
    {
        //return fibona(n-1)+fibona(n-2);
        ret = fibona(n-1)+fibona(n-2);
    }
    return ret;
}

void main()
{
    int n = 10;
    printf("fibona %d = %d \r\n", n ,fibona(n));	
}
