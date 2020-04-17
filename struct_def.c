#include<stdio.h>

struct boot{
    int a;
    const int b;
};

typedef struct {
   int a;
   int b;
}MyStruct;

struct bitS{
   int a:4;
   int  :4
   int b:4;
   int c:4;
   int d:4;
};

void main ()
{
    struct boot a1,a2;
    MyStruct u1,u2;
    a1.a = 1;
    //a1.b = 2;
    a2.a = 3;
    //a2.b = 4;
    u1.a = 5;
    u1.b = 6;
    printf("---debug---a1.a=%d, a1.b=%d, u1.a=%d, u1.b=%d \r\n", a1.a, a1.b, u1.a, u1.b);

    struct bitS x1;
    x1.a=1;
    x1.b=2;
    x1.c=3;
    printf("---debug---x1.a=%d, x1.b=%d, x1.c=%d, \r\n", x1.a, x1.b, x1.c);
}
