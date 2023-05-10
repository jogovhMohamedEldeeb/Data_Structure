
#define QUEUE_ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include"Paltform_Types.h"

typedef struct
{
    void **QueueArray;     /* pointer to array of void pointers  */
    uint32 QueueMaxSize;
    sint32 ElementCount;
    sint32 QueueFront;
    sint32 QueueRear;

}Queue_t;

typedef enum
{
    QUEUE_NOK = 0,
    QUEUE_OK ,           /* 1 */
    QUEUE_FULL,          /* 2 */
    QUEUE_EMPTY,         /* 3 */
    QUEUE_NULL_POINTER   /* 4 */
}QueueStatus_t;

Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status);
QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *itemPtr);
void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status);
void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status);
QueueStatus_t GetQueueElemnt(Queue_t *queue_obj, uint32 *QueueCount);
QueueStatus_t DestroyQueue(Queue_t *queue_obj);


