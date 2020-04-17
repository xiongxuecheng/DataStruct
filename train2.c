//a[n], return dupilcate one function

#include <stdio.h>
#include <stdlib.h>

int *checkDup(int a[], int n)
{
   int i,j,k;
   k =0;
   //int len = (int)n/2;
   printf("n=%d \r\n", n);
   int *ret = malloc(((int)n/2)*sizeof(int));
   for(i=0; i<n; i++) 
   {
	//printf("--a[%d]=%d------\r\n", i, a[i]);
	int count = 0;
	for(j=0; j<n;j++)
	{
	    //printf("--a[%d]=%d------\r\n", j, a[j]);
	    if (a[i] == a[j])
	    {
		count ++;
	    }
	    if (count >2)
	        break;
	}
	if (count = 2)
	{
	   ret[k] = a[i];
	}
   }
   ret[k+1]='\0';
   return ret;
}

void main()
{
    int ori[] = {2,3,4,6,7,3,4,5,6,4,5,5,3,2};
    int i;
    for (i=0; ori[i]!='\0'; i++)
    {
	printf("%d \r\n", ori[i]);
    }
    int *dup = checkDup(ori, sizeof(ori));
    for (i=0; dup[i]!='\0'; i++)
    {
        printf("dup[%d]=%d\r\n", i, dup[i]);
    }
     
//    char* ori = "2,3,4,6,7,3,4,5,6,4,5,5,3,2"
//    char* result = NULL;
//    result = strtok(ori, ",");
//    while(result != NULL)
//    {
//	result = strtok(NULL, ",");
//        printf("\r\n %s \r\n",result);
//    }
//    int input
//    dup = checkDup[]

}
