#include <stdio.h>

void main ()
{
    int a, b=1;
    for (a=1;a<7;a++)
    {
	for (b=1; b<a;b++)
	{
	    printf("%d   ",b);
	}
	printf("%d\r\n", a);
    }

}

