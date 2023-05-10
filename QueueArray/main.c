#include <stdio.h>
#include <stdlib.h>
#include"QueueArray.h"

uint32 Queue1MaxElement = 0;
Queue_t * Queue1;
void *RetVal = NULL;
uint32 QueueCount = 0;
uint32 Num1 = 0x11 , Num2 = 0x22,Num3 = 0x33 , Num4 = 0x44,Num5 = 0x55;
int main()
{
    QueueStatus_t  QueueStatus = QUEUE_NOK;
    printf("Please Enter number of elements in Queue : ");
    scanf("%d",&Queue1MaxElement);

    Queue1 = CreateQueue(Queue1MaxElement, &QueueStatus);
    printf("ox%X \n",Queue1);

    QueueStatus = EnqueueElement(Queue1,&Num1);printf("==> %i \n",QueueStatus); // 0
    QueueStatus = EnqueueElement(Queue1,&Num2);printf("==> %i \n",QueueStatus); // 1
    QueueStatus = EnqueueElement(Queue1,&Num3);printf("==> %i \n",QueueStatus); // 2

    QueueStatus = GetQueueElemnt(Queue1, &QueueCount);printf("==> %i \n",QueueStatus);
    printf("Count = %d \n",QueueCount);

    RetVal = QueueRear(Queue1, &QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Rear = 0x%X \n",*(uint32 *)RetVal);

    QueueStatus = EnqueueElement(Queue1,&Num4);printf("==> %i \n",QueueStatus); // 3
    QueueStatus = EnqueueElement(Queue1,&Num5);printf("==> %i \n",QueueStatus); // 4
    QueueStatus = EnqueueElement(Queue1,&Num5);printf("==> %i \n",QueueStatus); // 5

    QueueStatus = GetQueueElemnt(Queue1, &QueueCount);printf("==> %i \n",QueueStatus);
    printf("Count = %d \n",QueueCount);

    printf("\n-------------------\n");
    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Value = 0x%X \n",*(uint32 *)RetVal);

    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Value = 0x%X \n",*(uint32 *)RetVal);
    RetVal = QueueFront(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Front = 0x%X \n",*(uint32 *)RetVal);

    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Value = 0x%X \n",*(uint32 *)RetVal);


    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Value = 0x%X \n",*(uint32 *)RetVal);

    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);
    printf("Value = 0x%X \n",*(uint32 *)RetVal);

    RetVal = DequeueElement(Queue1,&QueueStatus);printf("==> %i \n",QueueStatus);

   QueueStatus = DestroyQueue(Queue1);
    return 0;
}
