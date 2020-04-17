#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///*c language to define a struct */
//struct example{
//    int a;
//    char b[10];
//};
///*Here to define struct variable */
//struct exampe value1;
///*Here to define a point variable which point to this kind type of struct */
//struct exampe *value2;

//Define a struct type 
typedef struct DataType {
    char name[16];
    char number[16];
}DataType;

typedef struct LinkList{
    DataType data;
    struct LinkList *next;
}LinkList,*LNode; 

int length = 0;
void create(LinkList *L)
{
    char flag = 'y';
    LinkList *p,*v;
    DataType *e;
    printf("input adress book information\r\n");
    p = L;
    while (flag == 'y' || flag == 'Y') 
    {
        v = (LNode)malloc(sizeof(LinkList));
        memset(v, 0 , sizeof(LinkList));
        DataType *tmp = &(v->data);
        printf("input Name\r\n");
        scanf("%s", tmp->name);
        printf("input Number\r\n");
        scanf("%s", tmp->number);
        v->next = NULL;
        p->next = v;
        p = v;
        length +=1;
        printf("going on to add contactor, input(Y/y)");
        getchar();
        scanf("%c", &flag);
    }
}

void printList(LinkList *L)
{
    LinkList *tmp = L->next; 
    DataType *Data = NULL;
    while (tmp !=NULL)
    {
        Data = &(tmp->data);
        printf ("%-12s", Data->name);
        printf ("%-12s \r\n", Data->number);
        tmp = tmp->next;
    }
}

void InsertList(LinkList *L, LNode node, int n)
{
    LinkList *p = L->next;
    int i = 1;
    if (n > length)
        i = length;
    while (p != NULL)
    {
        if (n = i)
        {
            node->next = p->next;
            p->next = node;
            break;
        } 
        p = p->next;
        i++;
    }
    return;
}

void delList(LinkList *L, const DataType data)
{
    LinkList *p = L->next;
    LinkList *last = L;
    while (p != NULL)
    {
        DataType *tmp = &(p->data);
        if(0 == strcmp(tmp->name, data.name))
        {
            last->next = p->next;
            free(p);
            break;
        }
        last = p;
        p = p->next;
        
    }
}

void main()
{
    char insert = 'i';
    int insertPosition = 0;
    LinkList *L = NULL;
    L = (LNode)malloc(sizeof(LinkList));
    L->next = NULL;
    create(L);
    printList(L);
    printf("insert List (i/I)");
    getchar();
    scanf("%c", &insert);
    while( insert == 'i' || insert =='I' )
    {
        printf("input insert position");
        getchar();
        scanf("%d", &insertPosition);

        LNode tmp = (LNode)malloc(sizeof(LinkList));
        DataType *DataTmp = &(tmp->data);
        printf("input name\r\n");
        scanf("%s", DataTmp->name);
        printf("input number\r\n");
        scanf("%s", DataTmp->number);
        tmp->next = NULL; 
        InsertList(L, tmp, insertPosition);
        printf("still insert List (i/I)");
        getchar();
        scanf("%s", &insert);
    }
    printList(L);
    ///here will process delete data
    DataType data;
    memset(&data,0,sizeof(DataType));
    printf("input name you want to delete");
    scanf("%s", data.name);
    printf("input number you want to delete");
    scanf("%s", data.number);
    delList(L, data);
    printList(L);
}
