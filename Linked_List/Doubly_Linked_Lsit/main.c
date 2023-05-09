#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;


//#define DELETE_NODE_AT_BEGINNING


struct Node
{
    uint32 NodeData;
    struct Node *Left_Link;
    struct Node *Right_Link;
};

struct Node *Head = NULL;

void Insert_At_Bgning(struct Node **List,uint32 Data);
void Insert_At_End(struct Node *List,uint32 Data);
void Insert_After(struct Node *List,uint32 Data,uint32 Position);
void Insert_Before(struct Node **List,uint32 Data,uint32 Position);
void Delete_At_Beginning(struct Node **List);
void Delete_At_End(struct Node *List);
void Delete_At_Intermediate(struct Node *List, uint32 position);
void display_Forward(struct Node *List);
void display_Backward(struct Node *List);

int main()
{
    Insert_At_Bgning(&Head,11);
    display_Forward(Head);
    Insert_At_Bgning(&Head,22);
    display_Forward(Head);
    Insert_At_Bgning(&Head,33);
    display_Forward(Head);
    Insert_At_End(Head,44);
    display_Forward(Head);
    Insert_After(Head,55,2);
    display_Forward(Head);
    Insert_Before(&Head,77,2);
    display_Forward(Head);
    Delete_At_Beginning(&Head);
    display_Forward(Head);
    Delete_At_End(Head);
    display_Forward(Head);
    Delete_At_Intermediate(Head,2);
    display_Forward(Head);


    return 0;
}

void Insert_At_Bgning(struct Node **List,uint32 Data)
{
    struct Node *TempNode = NULL;

    TempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;

          /* Check if List Empty */
        if(NULL == *List)
        {
            TempNode->Left_Link = NULL;
            TempNode->Right_Link = NULL;
            *List = TempNode;
        }
        else
        {
            TempNode->Right_Link = (*List);
            TempNode->Left_Link = NULL;
            (*List)->Left_Link = TempNode;
            (*List) = TempNode;
        }
    }
    else
    {
        printf("Can't allocate the new Node \n");
    }
}

void Insert_At_End(struct Node *List,uint32 Data)
{
    struct Node *TempNode = NULL;
    struct Node *Node_list_counter = NULL;

    TempNode = (struct Node *) malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        TempNode->Right_Link = NULL;
        Node_list_counter = List;
       while(NULL != Node_list_counter->Right_Link)
       {
           Node_list_counter = Node_list_counter->Right_Link;
       }
       TempNode->Left_Link = Node_list_counter; /* Now (Node_list_counter) is last Node */
       Node_list_counter->Right_Link = TempNode;
    }
    else
    {
        printf("Can't allocate the new Node !! \n");
    }
}
void Insert_After(struct Node *List,uint32 Data,uint32 Position)
{
    struct Node *TempNode = NULL;
    struct Node *Node_List_One = NULL; /* To point to Next Node where i add */
    struct Node *Node_List_Two = NULL; /* To point to previous Node where i add */

    Node_List_One = List;      /* points to the head node now */
    while(Position != 1) /* Traverse to reach previous node i want add after */
    {
        Node_List_One = Node_List_One->Right_Link;
        Position--;
    }

    TempNode = (struct Node *) malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
       TempNode->NodeData = Data;

       /* check if we reach to the end of the list :: adding new node at the end */
       if(NULL == Node_List_One->Right_Link)
       {
          Node_List_One->Right_Link = TempNode;
          TempNode->Left_Link = Node_List_One;
          TempNode->Right_Link = NULL;
       }
       else
       {
          Node_List_Two = Node_List_One->Right_Link;
          Node_List_One->Right_Link = TempNode;
          Node_List_Two->Left_Link = TempNode;
          TempNode->Left_Link = Node_List_One;
          TempNode->Right_Link = Node_List_Two;
       }
    }
    else
    {
        printf("Can't allocate the new Node !! \n");
    }

}
void Insert_Before(struct Node **List,uint32 Data,uint32 Position)
{
    struct Node *TempNode = NULL;
    struct Node *Node_List_One = NULL;
    struct Node *Node_List_Two = NULL;
    uint32 NodePosition = Position;

    Node_List_One = *List;
    while(NodePosition > Position-1) /* this to point before the given postion*/
    {
        Node_List_One = Node_List_One->Right_Link;
        NodePosition--;
    }
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        TempNode->NodeData = Data;
        if(1 == Position)
        {
            TempNode->Left_Link = NULL;
            TempNode->Right_Link = *List;
            (*List)->Left_Link = TempNode;
            *List = TempNode;
        }
        else
        {
            Node_List_Two = Node_List_One->Right_Link;
            Node_List_One->Right_Link = TempNode;
            Node_List_Two->Left_Link = TempNode;
            TempNode->Right_Link = Node_List_Two;
            TempNode->Left_Link = Node_List_One;
        }
    }
    else
    {
        printf("Can't allocate the new Node !! \n");
    }
}

void Delete_At_Beginning(struct Node **List)
{
    struct Node *TempNode = *List;

#ifdef DELETE_NODE_AT_BEGINNING   /* first way */
    *List = (*List)->Right_Link;
    (*List)->Left_Link = NULL;
    free(TempNode);
    TempNode = NULL;
#else                          /* Second way */
    *List = (*List)->Right_Link;
    free((*List)->Left_Link);
    (*List)->Left_Link = NULL;
#endif

}

void Delete_At_End(struct Node *List)
{
    struct Node *Node_List_One = NULL;
    struct Node *Node_List_Two = NULL;

    Node_List_One = List;
    while(Node_List_One->Right_Link != NULL)
    {
        Node_List_One = Node_List_One->Right_Link;
    }
    Node_List_Two =  Node_List_One->Left_Link;
    Node_List_Two->Right_Link = NULL;
    free(Node_List_One);
    Node_List_One = NULL;
}

void Delete_At_Intermediate(struct Node *List, uint32 position)
{
    struct Node *Node_List_One = NULL;
    struct Node *Node_List_Two = NULL;

    uint32 NodePosition = position;
    if(1 == NodePosition)
    {
        printf("Please use Delete_At_Beginning !! \n");
    }
    else
    {
        Node_List_One = List;
        while(NodePosition > 1)  /* suppose: Position = 3 */
        {
            Node_List_One = Node_List_One->Right_Link;
            NodePosition--;
        }
        Node_List_Two = Node_List_One->Left_Link;
        Node_List_Two->Right_Link = Node_List_One->Right_Link;
        Node_List_One->Right_Link->Left_Link = Node_List_Two;
        free(Node_List_One);
        Node_List_One = NULL;
    }
}

void display_Forward(struct Node *List)
{
    struct Node *TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ",TempNode->NodeData);
    while(NULL != TempNode->Right_Link)
    {
        TempNode = TempNode->Right_Link;
        printf("%d -> ",TempNode->NodeData);
    }
    if(NULL == TempNode->Right_Link)
    {
       printf("NULL \n");
    }
    printf("\n");
}

void display_Backward(struct Node *List)
{
     struct Node *TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    while(NULL != TempNode->Right_Link)
    {
        TempNode = TempNode->Right_Link;
    }
    while(NULL != TempNode)
    {
        printf("%d -> ",TempNode->NodeData);
        TempNode = TempNode->Left_Link;
    }
    if(NULL == TempNode)
    {
        printf("NULL \n");
    }
    printf("\n");
}
