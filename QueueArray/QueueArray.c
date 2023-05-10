#include"QueueArray.h"

static uint32 QueueIsFull(Queue_t *queue_obj);
static uint32 QueueIsEmpty(Queue_t *queue_obj);

Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *ret_status)
{
    Queue_t *my_queue = NULL;
    /* Create queue object in the heap to hold the queue information */
    my_queue =(Queue_t *) malloc(sizeof(my_queue));
    if(NULL == my_queue)
    {
        *ret_status = QUEUE_NOK;
        my_queue = NULL;
    }
    else
    {
        /* Create array of (void *) to hold the addresses of the Queue data */
        my_queue->QueueArray = (void **)calloc(maxSize,sizeof(void *));
        if(NULL == my_queue->QueueArray )
        {
            *ret_status = QUEUE_NOK;
            my_queue = NULL;
        }
        else
        {
            my_queue->ElementCount = 0;
            my_queue->QueueFront = -1;
            my_queue->QueueMaxSize = maxSize;
            my_queue->QueueRear = -1;
            *ret_status = QUEUE_OK;
        }
    }
    return my_queue;
}

QueueStatus_t EnqueueElement(Queue_t *queue_obj, void *itemPtr)
{
    QueueStatus_t QueueStatus = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == itemPtr))
    {
        QueueStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        /* Validate if the queue is not full */
        if(QueueIsFull(queue_obj))
        {
            QueueStatus = QUEUE_FULL;
        }
        else
        {
            (queue_obj->QueueRear)++;
            if(queue_obj->QueueRear == queue_obj->QueueMaxSize)
            {
                queue_obj->QueueRear = 0;
            }
            queue_obj->QueueArray[queue_obj->QueueRear] = itemPtr;

            /* if insert number when queue is empty */
            if(QueueIsEmpty(queue_obj))
            {
                queue_obj->QueueFront = 0;
                queue_obj->ElementCount = 1;
            }
            else
            {
                (queue_obj->ElementCount)++;
            }
            QueueStatus = QUEUE_OK;
        }
    }
    return QueueStatus ;
}

void *DequeueElement(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void *ReturnedElem = NULL;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if(!queue_obj->ElementCount)
        {
            *ret_status = QUEUE_EMPTY;
            ReturnedElem = NULL;
        }
        else
        {
            ReturnedElem = queue_obj->QueueArray[queue_obj->QueueFront];
            (queue_obj->QueueFront)++;
            /* queue front has wrapped to element 0 (Circular Queue) */
            if(queue_obj->QueueFront == queue_obj->QueueMaxSize)
            {
                queue_obj->QueueFront = 0;
            }
            else{/* Nothing */}

            /* if Queue has one element, and we will delete it */
            if(1 == queue_obj->ElementCount)
            {  /* Queue empty */
                queue_obj->QueueFront = -1;
                queue_obj->QueueRear = -1;
            }
            else{/* Nothing */}
            (queue_obj->ElementCount)--;
            *ret_status = QUEUE_OK;
        }

    }
    return ReturnedElem;
}

void *QueueFront(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void *ReturnedElem = NULL;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NOK;
        ReturnedElem = NULL;
    }
    else
    {
        /* Check if queue is Empty */
        if(!queue_obj->ElementCount)
        {
            *ret_status = QUEUE_EMPTY;
             ReturnedElem = NULL;
        }
        else
        {
            ReturnedElem = queue_obj->QueueArray[queue_obj->QueueFront];
            *ret_status = QUEUE_OK;
        }
    }
    return ReturnedElem;
}

void *QueueRear(Queue_t *queue_obj, QueueStatus_t *ret_status)
{
    void *ReturnedElem = NULL;
    if((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = QUEUE_NOK;
    }
    else
    {
        /* Check if queue is Empty */
        if(!queue_obj->ElementCount)
        {
            *ret_status = QUEUE_EMPTY;
             ReturnedElem = NULL;
        }
        else
        {
            ReturnedElem = queue_obj->QueueArray[queue_obj->QueueRear];
            *ret_status = QUEUE_OK;
        }
    }
    return ReturnedElem;
}

QueueStatus_t GetQueueElemnt(Queue_t *queue_obj, uint32 *QueueCount)
{
    QueueStatus_t QueueStatus = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == QueueCount))
    {
        QueueStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        /* Check if queue is Empty */
        if(!queue_obj->ElementCount)
        {
            *QueueCount = 0;
        }
        else
        {
            *QueueCount = queue_obj->ElementCount;
            QueueStatus = QUEUE_OK;
        }
    }
    return QueueStatus;
}

QueueStatus_t DestroyQueue(Queue_t *queue_obj)
{
    QueueStatus_t QueueStatus = QUEUE_NOK;
    if(NULL == queue_obj)
    {
        QueueStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        free(queue_obj->QueueArray);
        free(queue_obj);
        QueueStatus = QUEUE_OK;
    }
    return QueueStatus;
}

static uint32 QueueIsFull(Queue_t *queue_obj)
{
    return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

static uint32 QueueIsEmpty(Queue_t *queue_obj)
{
    return (queue_obj->ElementCount == 0);
}
