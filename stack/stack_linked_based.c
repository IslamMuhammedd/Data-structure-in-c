/******************************************************/
/*   AUTHOR      : Islam Mohamed                      */
/*   Description : Stack Linked Based                 */
/*   DATE        : 16 Dec 2021                        */
/*   VERSION     : V01                                */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode
{
    int data;
    struct stacknode* Next;
}StackNode;

typedef struct stack
{
    StackNode* Top;
    int size;
}Stack;

/************************************************/
/***************Functions Prototypes*************/
/************************************************/
void Stack_voidInitStack(Stack* ps);
void Stack_voidPush(int Copy_intValue, Stack* ps);
void Stack_voidPop(Stack* ps, int* pd);
void Stack_intReturnTopValue(Stack* ps, int* pd);
int  Stack_intIsEmpty(Stack* ps);
int  Stack_intIsFull(Stack* ps);
void Stack_voidClearStack(Stack* ps);
void Stack_voidPrint(Stack* ps);
int Stack_intSize(Stack* ps);

int main()
{
    int Top_Value, size;
    Stack s;

    Stack_voidInitStack(&s);
    
    Stack_voidPush(5,&s);
    Stack_voidPush(7,&s);
    Stack_voidPush(9,&s);
    
    Stack_voidPrint(&s);
    size= Stack_intSize(&s);
    
    printf("%d\n", size);
    
    Stack_voidClearStack(&s);
    
    Stack_voidPrint(&s);
    
    size= Stack_intSize(&s);
    printf("%d\n", size);
}

/************************************************/
/***************Functions Prototypes*************/
/************************************************/
void Stack_voidInitStack(Stack* ps)
{
    ps->Top = NULL;
    ps->size=0;
}

void Stack_voidPush(int Copy_intValue, Stack* ps)
{
    /*1- Create Node*/
    StackNode* pn= (StackNode*) malloc(sizeof(StackNode));
    /*2- Assign data section*/
    pn->data = Copy_intValue;
    /*3- Assign Next section*/
    pn->Next= ps->Top;
    /*3- Update Top Pointer*/
    ps->Top= pn;
    /*Increase size*/
    ps->size++;
}

void Stack_voidPop(Stack* ps, int* pd)
{
    if(!Stack_intIsEmpty(ps))
    {
        /*1- Return Top Node's Value*/
        *pd = ps->Top->data;
        /*2- Make Pointer to StackNode and intialize it with Top pointer*/
        StackNode* pn = ps->Top;
        /*3- Move ps->Top to the new Top Value*/
        ps->Top= pn->Next;  //ps->Top = ps->Top->Next;
        /*4- free pn*/
        free(pn);
        /*5- Decrease the size*/
        ps->size--;
    }
    else
        printf("There's No values to be popped\n");
}

void  Stack_intReturnTopValue(Stack* ps, int* pd)
{
    /*1- Return Top Node's Value*/
    *pd = ps->Top->data;
}

int  Stack_intIsEmpty(Stack* ps)
{
    if(ps->Top == NULL)
        return 1;
    else
        return 0;
}

int  Stack_intIsFull(Stack* ps)
{
    return 0;
}

void Stack_voidPrint(Stack* ps)
{
    /*1- Create pointer to StackNode*/
    StackNode* pn = ps->Top;
    /*Traverse on the stack till pn == NULL*/
    while(pn != NULL)
    {
        printf("%d\n", pn->data);
        pn = pn->Next;
    }
}

void Stack_voidClearStack(Stack* ps)
{
    /*1- Create pointer to StackNode*/
    StackNode* pn = ps->Top;
    /*Traverse on the stack till pn == NULL*/
    while(pn != NULL)
    {
        pn = pn->Next;
        free(ps->Top);
        ps->Top=pn;
    }
    ps->size=0;
}

int Stack_intSize(Stack* ps)
{
    return ps->size;
}

