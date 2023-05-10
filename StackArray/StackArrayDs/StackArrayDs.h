
#define STACK_ARRAY_H

#include<stdlib.h>
#include "Platform_Types.h"

typedef struct
{   void **StackArray;   /* Points to the array that allocated in the heap */
    sint32 StackTop;
    sint32 Elementcount;
    uint32 StackMaxSize;
}stack_t;


typedef enum
{   STACK_NOK = 0,        /* Stack operation not performed successfully */
    STACK_OK,             /* Stack operation performed successfully  */
    STACK_FULL,           /* Stack is full */
    STACK_EMPTY,          /* Stack is empty */
   // STACK_NULL_POINTER    /* NULL pointer passed to the Stack operations */
}StackStatus_t;


stack_t* CreateStack(uint32 MaxSize,StackStatus_t *ret_status);
stack_t* DestroyStack(stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t PushStack(stack_t *stack_obj, void* itemPtr);
void* PopStack(stack_t* stack_obj, StackStatus_t *ret_status);
void* StackTop(stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t Stackcount(stack_t* stack_obj, uint32 *ret_status);
