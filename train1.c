#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
void getMem(char **input)
{
    if (input == NULL)
	return;
    *input = (char *)malloc(BUFFER_SIZE);
    return;
}

void main ()
{
    char* pzbuf = NULL;
    getMem(&pzbuf);
    strcpy(pzbuf, "this is a test\r\n");
    printf("%s",pzbuf);
    free(pzbuf);
    pzbuf = NULL;
}
