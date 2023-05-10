
#include "StackArrayDs.h"

static StackIsEmpty(stack_t *stack_obj);
static StackIsFull(stack_t *stack_obj);

stack_t* CreateStack(uint32 MaxSize,StackStatus_t *ret_status)
{
    stack_t *my_stack = NULL;
    if(NULL == ret_status)
    {
        *ret_status = STACK_NOK;
         my_stack = NULL;
    }
    else
    {
        my_stack =(stack_t *) malloc(sizeof(stack_t));
        if(!my_stack)
        {
            *ret_status = STACK_NOK;
             my_stack = NULL;
        }
        else
        {
            my_stack->Elementcount = 0;
            my_stack->StackMaxSize = MaxSize;
            my_stack->StackTop = -1;
            my_stack->StackArray =(void **) calloc(my_stack->StackMaxSize,sizeof(void *));
            if(!my_stack->StackArray)
            {
                *ret_status = STACK_NOK;
                 my_stack = NULL;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }
    return my_stack;
}

stack_t* DestroyStack(stack_t* stack_obj, StackStatus_t *ret_status)
{
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = STACK_NOK;
    }
    else
    {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_NOK;
    }
    return NULL;
}

StackStatus_t PushStack(stack_t *stack_obj, void* itemPtr)
{
    StackStatus_t StackStatus = STACK_NOK;
    if((NULL == stack_obj) || (NULL == itemPtr))
    {
        StackStatus = STACK_NOK;
    }
    else
    {
        if(StackIsFull(stack_obj))
        {
            StackStatus = STACK_FULL;
        }
        else
        {
            (stack_obj->StackTop)++;
            (stack_obj->StackArray[stack_obj->StackTop]) = itemPtr;
            (stack_obj->Elementcount)++;
            StackStatus =STACK_OK;
        }
    }
    return StackStatus;
}

void* PopStack(stack_t* stack_obj, StackStatus_t *ret_status)
{
    void *dataPtrout = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = STACK_NOK;
        dataPtrout = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            dataPtrout = NULL;
        }
        else
        {
            dataPtrout = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->Elementcount)--;
            *ret_status = STACK_OK;
        }
    }
    return dataPtrout;
}

void* StackTop(stack_t* stack_obj, StackStatus_t *ret_status)
{
    void *dataPtrout = NULL;
    if((NULL == stack_obj) || (NULL == ret_status))
    {
        *ret_status = STACK_NOK;
        dataPtrout = NULL;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            *ret_status = STACK_EMPTY;
            dataPtrout = NULL;
        }
        else
        {
            dataPtrout = stack_obj->StackArray[stack_obj->StackTop];
            *ret_status = STACK_OK;
        }
    }
    return dataPtrout;

}

StackStatus_t Stackcount(stack_t* stack_obj, uint32 *stack_count)
{
    StackStatus_t StackStatus = STACK_NOK;
    if((NULL == stack_obj) || (NULL == stack_count))
    {
        StackStatus = STACK_NOK;
    }
    else
    {
        if(StackIsEmpty(stack_obj))
        {
            StackStatus = STACK_EMPTY;
        }
        else
        {
            *stack_count = stack_obj->Elementcount;
            StackStatus = STACK_OK;
        }
    }
    return StackStatus;
}

static StackIsEmpty(stack_t* stack_obj)
{
    return (stack_obj->Elementcount == 0);
}

static StackIsFull(stack_t* stack_obj)
{
    return (stack_obj->Elementcount == stack_obj->StackMaxSize);
}

