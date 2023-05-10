#include <stdio.h>
#include <stdlib.h>
#include"StackArrayDs.h"

stack_t *stack1= NULL;
uint32 Stack_Size = 0;
uint32 var1 = 0x11;
uint32 var2 = 0x22;
uint32 var3 = 0x33;
uint32 Count = 0;
void *Stack_ret = NULL;

int main()
{
   /* StackStatus_t Stack1_Status = STACK_NOK;


    printf("Enter number of element : ");
    scanf("%d",&Stack_Size);
    stack1 = CreateStack(Stack_Size, &Stack1_Status);
    if(stack1)
    {
        printf("Stack 1 created \n");
    }
    Stack1_Status = PushStack(stack1, &var1); printf("Stack1_Status = %i \n",Stack1_Status);
    Stack1_Status = PushStack(stack1, &var2); printf("Stack1_Status = %i \n",Stack1_Status);
    Stack1_Status = PushStack(stack1, &var3); printf("Stack1_Status = %i \n",Stack1_Status);

    Stack1_Status = Stackcount(stack1, &Count); printf("Stack1_Status = %i \n",Stack1_Status);
    printf("Count = %d \n",Count);



    Stack_ret = StackTop(stack1, &Stack1_Status); printf("Stack1_Status = %i \n",Stack1_Status);
    printf("StackTop = 0x%X \n",*(uint32 *) Stack_ret);

    Stack_ret = PopStack(stack1, &Stack1_Status); printf("Stack1_Status = %i \n",Stack1_Status);
    printf("Value poped  = 0x%X \n",*(uint32 *) Stack_ret);

    stack1 = DestroyStack(stack1, &Stack1_Status);
    if(!stack1)
    {
        printf("Stack 1 created \n");
    }*/
    int n1=2,n2=3;
    /*scanf("%d%d",&n1,&n2);
    int ans=n1-(n1/n2)*n2;
    printf("Modulus = %d \n",ans);*/
    /*n1++;
    printf("%d \n", ++n1);
    int t=n1++;
    printf("%d \n", t);*/
    int x=6,y=7,z=8,w;
    w=(x++) + (y++) + (--z);
    printf("W = %d \n", w);

    return 0;
}
