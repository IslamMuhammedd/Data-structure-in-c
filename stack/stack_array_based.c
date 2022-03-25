/**********************************/
/*   Author : Islam Mohamed       */
/*   SW : Stack                   */
/*   Version : V1.0               */
/*   Date : 15/12/2021            */
/**********************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct stack
{
    int arr[MAX_SIZE];
    int top;
}Stack ;

/* Function Protoypes */
void Stack_voidInitStack(Stack* ps);
void Stack_voidPush (int Copy_intValue ,Stack* ps );
void Stack_voidPop(Stack* ps);
int Stack_intReturnTopValue( Stack* ps);
int Stack_intIsEmpty(Stack* ps);
int Stack_intIsFull(Stack* ps);
void Stack_voidPrint(Stack* ps);



void main()
{
        Stack s;
        int Top_Value;
        
         Stack* ps=&s;

        Stack_voidInitStack(ps);
        Stack_voidPush(5,ps);
        Stack_voidPush(7,ps);
        Stack_voidPush(3,ps);
        Stack_voidPush(8,ps);
        Stack_voidPush(10,ps);
        Top_Value=Stack_intReturnTopValue(ps);
        Stack_voidPop(ps);
        printf("%d",Top_Value);     


}

void Stack_voidInitStack(Stack* ps)
{
    //top holds -1 "out of range"
    ps ->top=-1;
}

void Stack_voidPush (int Copy_intValue ,Stack* ps )
{
    if (!Stack_intIsFull(ps))
    {
        //Incremnting Top
        ps->top ++;
        //Assigning the value into the index
        ps->arr[ps->top]=Copy_intValue;
    }
    else
        printf("The Stack is full , can't Push/insert any elements \n");
}

void Stack_voidPop(Stack* ps)
{
    if (!Stack_intIsEmpty(ps))
    {
        ps->top--;
    }
    else
        printf("There is no value to be poped \n");
}
int Stack_intReturnTopValue( Stack* ps)
{   
    if (!Stack_intIsEmpty(ps))
        return ps->arr[ps->top];
    else
    {
        printf("There is no value to be poped \n");
        return 0;
    }
}
int Stack_intIsEmpty(Stack* ps)
{
    if (ps->top==-1)
        return 1;
    else 
        return 0;    

}
int Stack_intIsFull(Stack* ps)
{
    return (ps->top==MAX_SIZE-1) ;
        
       
}
void Stack_voidPrint(Stack* ps)
{
    int Iter =ps->top;
    while (Iter!=-1)
    {
        printf ("%d" , ps->arr[Iter]);
        Iter --;
    }
    

}
