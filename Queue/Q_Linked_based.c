/*** ******************************** **************/
/* Author : Islam Mohamed                          */
/* SW : Queue Linked Based                          */
/* Date : 18 Dec 2021                              */
/* *************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{   
    // Each Queue node has Two fields data and pointer to next node

    int Data;
    struct queueNode* Next;
    
} QueueNode;

typedef struct queue
{   
    // Each Queue has Two indicators Front ,Rear and size field

    /* fornt always refers to the firsr element in the queue*/
    QueueNode* Front;
    QueueNode* Rear;
    int Size;
} Queue;

/* Functions Prototypes */

void Queue_voidInitQueue(Queue * pq);
void Queue_voidPush(int copy_char, Queue * pq);
void Queue_voidPop(Queue * pq , int* pd);
void Queue_intReturnTopValue(Queue * pq, int* pd);
int Queue_IntIsEmpty(Queue * pq);
int Queue_IntIsFull(Queue * pq);
void Queue_voidPrintQueue(Queue * pq);
int Queue_intSize(Queue * pq);
void Queue_voidClearQueue(Queue * pq);

int main()
{   int dequeued_value , size;
    Queue q;
    Queue_voidInitQueue(&q);
    Queue_voidPush(5,&q);
    Queue_voidPush(8,&q);
    Queue_voidPush(2,&q);
    
    
    Queue_voidPrintQueue(&q);

    size = Queue_intSize(&q);
    printf("the size before Dequeing is %d",size);
    printf("\n =======================\n");

    Queue_voidPop(&q, &dequeued_value);
    printf("the Deuqued Value is %d ",dequeued_value);
    printf("\n =======================\n");

    size =Queue_intSize(&q);
    printf("The size after Dequeuing is %d\n",size);

    printf("\n =======================\n");
    Queue_voidClearQueue(&q);
    size =Queue_intSize(&q);
    printf("The size after clearing is %d\n",size);

    return 0;
}

void Queue_voidInitQueue(Queue * pq)
{   
    // Both holds values out of the bounds
    pq -> Front = NULL;
    pq -> Rear = NULL;
    pq->Size = 0;
}

void Queue_voidPush(int copy_int, Queue * pq)

{   
   
    if(!Queue_IntIsFull(pq))
    
    {
        //1 create a node
        QueueNode* pn=(QueueNode*) malloc(sizeof(QueueNode));
        //2 assigning the value into data field
        pn->Data = copy_int;
        //3 assign null to the next
        pn->Next = NULL;    
        // the previous ones are constant

        // update the next of rear " note the rear still the same we control the next only"
        // very important and visualize it to understand            
        if(pq->Front == NULL) // Handling the first element
            pq->Front = pn;
        
        else    
            pq->Rear->Next = pn;
        
        // updating the rear itself
        pq->Rear = pn;

        pq->Size++;
    }
    else    
        printf("Queue is Full! \n");

}

void Queue_voidPop(Queue * pq , int *pd)

{   /*if(pq->Front == NULL)
    {
        pq->Rear = NULL;
    }*/
    
    // make a temp pointer 
    QueueNode* pn = pq->Front;
    // return the data
    *pd = pn->Data;
    // move to next node
    pq->Front = pq->Front->Next;

    /* To handle the last element when dequeuing and satisfy the empty conditions */ 
    if(pq->Front == NULL)
        {
            pq->Rear = NULL;
        }
    pq->Size --;
    
    free(pn);

    //else 
      //  printf("Sorry the Queue is empty \n");


}
void Queue_intReturnFrontValue(Queue * pq, int* pd)
{    
    if(!Queue_IntIsEmpty(pq))
        
        {   
            // Make a temporary pointer
            QueueNode* pn = pq->Front;

            // Return the node data
            *pd = pn->Data;

            // Update the front to next node
            pq->Front = pq->Front->Next;

            // Handling the last element
            if(pq->Front == NULL)
                {
                    pq->Rear = NULL;
                }    free(pn);

            pq->Size--;
        }
}

int Queue_IntIsEmpty(Queue * pq)
{
    return (pq->Front == NULL);
}

int Queue_IntIsFull(Queue * pq)
{
    return 0;
}

void Queue_voidClearQueue(Queue * pq)
{   
    // Make a temporary pointer

    QueueNode* pn = pq->Front;

    if (pq->Front!= NULL)
        {   
            /*pn = pn->Next;
            free(pq->Front);
            pq->Front=pn;*/
            pq->Front=pq->Front->Next;
            free(pn);

            printf("the Queue is Cleared\n");
        }
    else if(pq->Front == NULL)
        {
            pn->Next = NULL;
            free(pn);
            printf("The Queue is Cleared");
        }

    pq->Size =0;
     
    /*if(!Queue_IntIsEmpty(pq))
    {
        for(int i = pq->Front ; i<= pq->Rear ; i++ )
        {
            printf("%d \n", pq->Arr[i]);
        }
    
    }
    else
    {
        printf("")

    }*/
}

int Queue_intSize(Queue* pq)
{
    return (pq->Size);
}

void Queue_voidPrintQueue(Queue * pq)
{
    /*1- Create pointer to QueueNode*/
    QueueNode* pn = pq->Front;
    /*Traverse on the stack till pn == NULL*/
    while(pn != NULL)
    {
        printf("%d\n", pn->Data);
        pn = pn->Next;
    }
}