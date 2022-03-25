/*** ******************************** **************/
/* Author : Islam Mohamed                          */
/* SW : List Linked Based                          */
/* Date : 19 Dec 2021                              */
/* *************************************************/

#include <stdio.h>
#include <stdlib.h>

// for generic purpose if you want to change it to list of strings or chars 
// so you will change only this line below to be char ;)
typedef int ListEntry;

typedef struct listNode
{ /* Data field of each List Node*/
    ListEntry Data;

    /* Pointer to the next Node*/
    // Note : it shouldn't be "ListNode* Next" , because its not declared till now its declared down
    // it's tricky and interview question
    struct listNode* Next;

} ListNode;

typedef struct list
{
    // The List it self has only pointer to the Linked List itself
    // and size field to determine the size of List

    ListNode *Head;
    int Size;
} List;

/***************************/
/* Functions Prototypes    */
/***************************/

void List_voidInitList(List *pl);
void List_voidInsertList(int pos, List *pl, int copy_intValue);
void List_voidReplaceList(int pos, List *pl, int new_value);
void List_voidDeleteList(int pos, List *pl, int *pd);
void List_voidRetrieveList(int pos, List *pl, int *pd);

int List_intIsEmpty(List *pl);
int List_intIsFull(List *pl);
int List_intSize(List *pl);
void List_voidPrintList(List *pl);
void List_voidDestroyList(List *pl);

int main()
{
    int size, retrieved_value;
    List L;
    List_voidInitList(&L);

    List_voidInsertList(0, &L, 7);
    List_voidInsertList(1, &L, 10);
    List_voidInsertList(2, &L, 6);
    List_voidInsertList(3, &L, 8);
    List_voidPrintList(&L);
    size = List_intSize(&L);
    printf("The Size of The list before retrieving = %d\n", size);

    printf("\n====================\n");
    List_voidRetrieveList(2, &L, &retrieved_value);
    printf("The Retrieved Value is %d\n", retrieved_value);
    size = List_intSize(&L);
    printf("The Size of The list After Retrieving = %d\n", size);

    printf("\n========================\n");
    List_voidDeleteList(2, &L, &retrieved_value);
    size = List_intSize(&L);
    printf("The Size of The list After Deleting = %d\n", size);
    List_voidPrintList(&L);

    printf("\n========================\n");
    List_voidReplaceList(0, &L, 2);
    printf("The List After Replacing is \n");
    List_voidPrintList(&L);
    List_voidDestroyList(&L);
    size = List_intSize(&L);
    printf("\nThe Size of The list After Destroying = %d\n", size);
    List_voidPrintList(&L);
    return 0;
}

void List_voidInitList(List *pl)
{
    // Initializing the Head and Size

    pl->Head = NULL;
    pl->Size = 0;
}

void List_voidInsertList(int pos, List *pl, int copy_intValue)
{
    // For Handling inserting at any position

    ListNode *q;
    int i;

    /* 1- Creation of node*/
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode));

    /* 2- Assigning the Data and Next Pointer */
    pn->Data = copy_intValue;
    pn->Next = NULL;

    /* 3-Handling the first Node if it's empty or had a node */

    if (pos == 0)
    {
        pn->Next = pl->Head; // if there was a node at first
        pl->Head = pn;       // update the head it self
    }
    /* 4- Handling any node in between*/
    else
    {
        for (q = pl->Head, i = 0; i < pos - 1; i++)
        {
            q = q->Next;
        }
        pn->Next = q->Next;
        q->Next = pn;
    }

    pl->Size++;
}

void List_voidReplaceList(int pos, List *pl, int new_value)
{
    ListNode *q;
    int i;

    for (q = pl->Head, i = 0; i < pos; i++)
    {
        q = q->Next;
    }
    q->Data = new_value;
}
void List_voidDeleteList(int pos, List *pl, int *pd)
{
    int i;
    ListNode *q;
    ListNode *temp; // for holding the rest of the list

    if (pos == 0)
    {
        *pd = pl->Head->Data;

        temp = pl->Head->Next;

        free(pl->Head);

        pl->Head = temp;
    }
    else
    {
        for (q = pl->Head, i = 0; i < pos - 1; i++)
        {
            q = q->Next;
        }
        *pd = q->Next->Data;

        temp = q->Next->Next; // for holding the rest of the list

        free(q->Next);

        q->Next = temp;
    }
    pl->Size--;
}

void List_voidRetrieveList(int pos, List *pl, int *pd)
{
    int i;
    ListNode *q;

    for (q = pl->Head, i = 0; i < pos; i++)
    {
        q = q->Next;
    }
    *pd = q->Data;
}

int List_intIsEmpty(List *pl)
{
    return (pl->Head == NULL);
}

int List_intIsFull(List *pl)
{
    return 0;
}
int List_intSize(List *pl)
{
    return (pl->Size);
}
void List_voidPrintList(List *pl)
{
    ListNode *q = pl->Head;

    while (q != NULL)
    {
        printf("%d\n", q->Data);
        q = q->Next;
    }
}

void List_voidDestroyList(List *pl)
{
    ListNode *temp;

    while (pl->Head != NULL) // while(pl->Head)
    {
        // Visualiseeeee

        ListNode *temp = pl->Head->Next;
        free(pl->Head);
        pl->Head = temp;
    }
    pl->Size = 0;
    printf("\nThe List is Empty Now After Destroying");
}