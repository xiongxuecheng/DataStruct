#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    int value1;
    char* value2;
    struct Node *next;
}Node;

typedef struct Head
{
    int Length;
    struct Node *Head;
}List;

#define err(input) printf("%s",input);

//init HEAD->next = NULL , this is list with head case
void initNode(Node **P)
{
    *P = (Node *)malloc(sizeof(struct Node));
    (*P)->value2 = (char *)malloc(sizeof(char));
    (*P)->value1 = 0;
    (*P)->next = NULL;
}

//this case is head can be a node list
//input value L is the head of the list
//input value data is a struct value need added to the list
void insertEndList(Node *L, const Node data)
{
    Node *p = NULL;
    p = (Node *)malloc(sizeof(struct Node));
    p->value1 = data.value1;
    p->value2 = (char *)malloc(sizeof(char));
    strcpy(p->value2, data.value2);
    p->next = NULL;
    if (L == NULL) // when the list head is a node, and the list is empty
        L = p;
    else{ 
        while (L->next != NULL)
            L = L->next;
        L->next = p; 
    }
}

Node* insertHeadList(Node *L, const Node data)
{
   Node *p = NULL; 
   p = (Node *)malloc(sizeof(struct Node));
   p->value1 = data.value1;
   p->value2 = (char *)malloc(sizeof(char));
   strcpy(p->value2, data.value2);
   p->next = L;
   return p;
}

//this case is head can't be a node list
//input value L is the head of the list
//P is the node already initiatied, need insert to the end of the list 
void insertEndList1(Node *L, Node *P)
{
    if (L == NULL)
    {
        err("input list is error without HEAD");
        return;
    }
    while (L->next != NULL)
        L = L->next;
    L->next = P; 
}
void insertHeadList1(Node *L, Node *P)
{
    if (L == NULL)
    {
        err("input list is error without HEAD");
        return;
    }
    P->next = L->next;
    L->next = P;
}

void deleteFromEnd(Node *L)
{
    //List without head case
    if (L == NULL)
        return;
    while (L->next != NULL)
        L = L->next;
    free(L);
}
void deleteFromFirst(Node *L)
{
    //List without head case
    if (L == NULL)
        return;
    Node *P = L->next;
    while (P != NULL)
    {
        L->next = P->next;
        free(P);
        P = NULL;
        P = L->next;
    }
}

void emptyListNoHead(Node *L)
{
    //List without head case
    while(L != NULL)
    {
        Node *tmp = L;
        L = L->next;
        free(tmp);
    }
}
    
void emptyListWithHead(Node *L)
{
    //List with head case, L is head
    if (L == NULL) //make sure head is valid
    {
        err("input head is wrong");
        return;
    }

    Node *P = L->next; 
    while ( P != NULL) //when node is valid
    {
        L->next = P->next;
        free (P);
        P = L->next;
    }
}

void printList(Node *L)
{
    while(L->next != NULL) 
    {
        L = L->next;
        printf("list value2 = %s \r\n",L->value2); 
    }
}

#define LEN 64
void main()
{
    int i = 0;
    char a[LEN]= "this is my test";
    //char *a = "this is my test";
    char *tmp = (char*)malloc(LEN);  
    Node *L = (Node *)malloc(sizeof(struct Node)); 
    L->next = NULL;
    
    while (a[i] != '\0')
    {
        if (a[i] != ' ')
        {
            tmp = strncat(tmp,&a[i],1);
        }
        if (a[i] == ' ' || a[i+1] == '\0')
        {
            Node *P = NULL;
            initNode(&P);
            strcpy(P->value2, tmp);
            insertEndList1(L, P);
            memset(tmp,0, LEN);  
        }
        i++;
    }
    printList(L);
}
