/*** ******************************** **************/
/* Author : Islam Mohamed                          */
/* SW : Queue Array Based                          */
/* Date : 15 Dec 2021                              */
/* *************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct queue
{   
    // Each Queue has an Array and Two indicators at Front and Rear

    int Arr[MAX_SIZE];
    int Front;
    int Rear;
    int Size;
} Queue;

/************************/
/* Functions Prototypes */
/************************/

void Queue_voidInitQueue(Queue * pq);
void Queue_voidPush(int copy_char, Queue * pq);
void Queue_voidPop(Queue * pq , int* pd);
void Queue_intReturnFrontValue(Queue * pq, int* pd);
int  Queue_IntIsEmpty(Queue * pq);
int  Queue_IntIsFull(Queue * pq);
void Queue_voidPrintQueue(Queue * pq);
int  Queue_intSize(Queue * pq);

int main()
{   
    int dequeued_value , size;

    Queue q;
    Queue_voidInitQueue(&q);
    Queue_voidPush(5,&q);
    Queue_voidPush(12,&q);
    Queue_voidPush(9,&q);
    
    Queue_voidPrintQueue(&q);
    size = Queue_intSize(&q);
    printf("the size before Dequeing is %d",size);
    printf("\n =======================\n");
    
    Queue_voidPop(&q, &dequeued_value);
    printf("the Deuqued Value is %d ",dequeued_value);
    printf("\n =======================\n");

    size =Queue_intSize(&q);
    printf("The size after Dequeuing is %d\n",size);

    printf("The Elements after Dequeuing are \n");
    Queue_voidPrintQueue(&q);

    return 0;
}

void Queue_voidInitQueue(Queue * pq)
{   
    // Both holds values out of the Array at initialization

    pq -> Front = -1;
    pq -> Rear = -1;
    pq->Size = 0;
}

void Queue_voidPush(int copy_int, Queue * pq)

{   
    // Check if it full or not

    if(!Queue_IntIsFull(pq))
    
    {
        if(Queue_IntIsEmpty(pq))        // Handling the first Enqueue operation /*pq->Front==-1*/
            pq -> Front = 0;
    
        pq-> Rear++;
        pq->Arr[pq->Rear] = copy_int;

        pq->Size++;
    }
    else    
        printf("Queue is Full! \n");

}

void Queue_voidPop(Queue * pq , int *pd)
{   
    
    if(!Queue_IntIsEmpty(pq))
    {   
        // return the front value
        //void Queue_intReturnFrontValue(Queue * pq, int* pd)  instead of the next line 

        *pd = pq->Arr[pq->Front];

        pq -> Front++;

        pq->Size--;

        //Handling the last element of the queue
        if(pq->Front > pq->Rear)
        {
            pq->Front = -1;
            pq ->Rear = -1;
        }   
    }
    else 
        printf("Sorry the Queue is empty \n");
}

void Queue_intReturnFrontValue(Queue * pq, int* pd)
{   
     if(!Queue_IntIsEmpty(pq))
    {   
        // return the front value

        *pd = pq->Arr[pq->Front];

        pq -> Front++;

        pq->Size--;
    }
}

int Queue_IntIsEmpty(Queue * pq)

{
    return (pq->Front == -1);
}

int Queue_IntIsFull(Queue * pq)
{
    return(pq->Rear == MAX_SIZE);
}

void Queue_voidPrintQueue(Queue * pq)
{
    if(!Queue_IntIsEmpty(pq))
    {
        for(int i = pq->Front ; i<= pq->Rear ; i++ )
        {
            printf("%d \n", pq->Arr[i]);
        }
    
    }
    else
    {
        printf("Sorry the Queue is Empty");

    }
}

int Queue_intSize(Queue* pq)
{
    return pq->Size;
}

/*void Queue_voidClearQueue(Queue * pq)
{
    if(!Queue_IntIsEmpty(pq))
    {
        for(int i = pq->Front ; i<= pq->Rear ; i++ )
        {
            printf("%d \n", pq->Arr[i]);
        }
    
    }
    else
    {
        printf("Sorry the Queue is Empty");

    }
}*/