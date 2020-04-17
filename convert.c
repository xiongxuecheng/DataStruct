#include <string.h>
#include <stdio.h>
#include <malloc.h>

char *convert_M1(char* oriPath, int bufSize)
{
   char* outPath =(char *)malloc(sizeof(char)*bufSize)
   memset(outPath, 0, sizeof(char)*bufSize);
   char* tmp = NULL;
   char* p = strtok(oriPath,'/');
   while (p != NULL)
   {
	if (strcmp(p, "..") != 0)
	{
            strcat(outPath,'/');
            strcat(outPath,p);
	}
	else
	{
            tmp = outPath + strlen(outPath); // count offset of the end   
	    while (*tmp != '/')
	    {
		tmp--;
	    }
            *tmp = '\0';
	}
	p = strtok(NULL, '/');
   }
}

char *convert(const char* rpath, int buf_size)
{
    char *p = NULL;
    char *q = NULL;
    char *dest = malloc(buf_size);
    memset(dest, 0, buf_size);
    char *tmp = malloc(buf_size);
    memset(tmp, 0, buf_size);
    strcpy(tmp, rpath);
    for(p = strtok(tmp, "/"); p != NULL; p=strtok(NULL, "/"))
    {
        printf("\n p=%s\n", p);
        if(strcmp(p, "..") != 0)
        {
            strcat(dest,"/");
            strcat(dest,p);
            printf("\ndest=%s\n",dest);
        }
        else
        {
            q = dest + strlen(dest); 
            printf("\n q=%s, len=%d\n ", q, strlen(dest));
            while (*q != '/')
            {
                q--; 
            }
            *q = '\0';
        }
    }
    free(tmp);
    strcat(dest,"/");
    return dest;
}

int main()
{
    int len = 10;
    char a[] = "/home/abc/tmp/../new/./";

    char *b = convert(a,256);
    printf("\na=%s;b=%s \n",a,b);
}
