#include "stdlib.h"
#include "string.h"
#include "stdio.h"
char * defangIPaddr(char * address){
    int len = strlen(address);
    char *res = malloc(sizeof(char *)*(7+len));
    int i = 0, j=0;
    while (i < len)
    {
        res[j++]=address[i];
        if (res[i+1] == '.')
        {
            res[j++]='[';
            res[j++]=address[++i];
            res[j++]=']';
        }
        i++;
    }
    res[j]='\0';
    return res;
}

void main ()
{
    char *input ="123.123.123.123";
    char *res = defangIPaddr(input);
    printf("-----debug-----res=%s\r\n", res);
}

