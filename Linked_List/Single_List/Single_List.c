

#include"Single_List.h"

struct Node *Head = NULL;

void Insert_At_Begning(struct Node **List)
{
    struct Node *TempNode = NULL;
    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        printf("Enter Data Node : ");
        scanf("%d",&TempNode->DataNode);
        /* Check if list is Empty */
        if(NULL == *List)
        {
            TempNode->NodeLink = NULL;
            *List = TempNode;
        }

        else
        {
            TempNode->NodeLink = *List;
            *List = TempNode;
        }
    }
    else{
        /* Nothing */
    }
}

void Insert_At_end(struct Node **List)
{
    struct Node *TempNode = NULL;
    struct Node *LastNode = NULL;

    TempNode = (struct Node *) malloc(sizeof(struct Node));
    if(NULL != TempNode)
    {
        printf("Enter Data Node : ");
        scanf("%d",&TempNode->DataNode);
        TempNode->NodeLink = NULL;

        if(NULL == TempNode)
        {
            *List = TempNode;
        }
        else
        {
            LastNode = *List;
            while(LastNode->NodeLink != NULL)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = TempNode;
        }
    }
    else{
        /* Nothing */
    }
}

void Insert_At_After(struct Node *List)
{
    struct Node *TempNode = NULL;
    struct Node *Node_List_Counter = NULL;
    int ListLength = 0;
    int Node_Position = 0;
    int Node_counter = 1;

    printf("Enter Position : ");
    scanf("%d",&Node_Position);

    ListLength = Get_Length(List);
    if(Node_Position > ListLength)
    {
        printf("Invalid Position !! \n");
    }
    else
    {
        Node_List_Counter = List;
        while(Node_counter < Node_Position)
        {
            Node_counter++;
            Node_List_Counter = Node_List_Counter->NodeLink;
        }
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if(NULL != TempNode)
        {
            printf("Enter Data Node : ");
            scanf("%d",&TempNode->DataNode);

            TempNode->NodeLink = Node_List_Counter->NodeLink;
            Node_List_Counter->NodeLink = TempNode;
        }
        else{
            /* Nothing */
        }

    }
}

int Get_Length(struct Node *List)
{
    struct Node *TempNode = List;
    int counter = 0;
    while(NULL != TempNode)
    {
        counter++;
        TempNode = TempNode->NodeLink;
    }
    return counter;
}
void display(struct Node *list)
{
    struct Node *TempNode = list;
    printf("Values : ");
    if(NULL == list)
    {
        printf("Empty List !! \n");
    }
    while(TempNode != NULL)
    {
        printf("%d ->",TempNode->DataNode);
        TempNode = TempNode->NodeLink;
    }
    printf("NULL \n");
}

void Delete_Node_At_Beginning(struct Node **List)
{
    struct Node *TempNode =  *List;
    int ListLenght = 0;

    ListLenght = Get_Length(List);
    if(ListLenght == 0)
    {
        printf("Empty List !! \n");
    }
    else
    {
        *List = TempNode->NodeLink;
        TempNode->NodeLink = NULL;
        free(TempNode);
    }
}
void Delete_Node(struct Node *List)
{
    struct Node *Node_List_Counter = List;
    struct Node *Next_Node = List;
    int List_Length = 0;
    int Node_Position = 0;
    int Counter = 1;


    printf("Enter Position Node To Delete : ");
    scanf("%d",&Node_Position);

    List_Length = Get_Length(List);
    if(Node_Position > List_Length)
    {
        printf("Invalid Position !! \n");
    }
    else
    {
        while(Counter < (Node_Position - 1))
        {
            Counter++;
            Node_List_Counter = Node_List_Counter->NodeLink;
        }
        Next_Node = Node_List_Counter->NodeLink;
        Node_List_Counter->NodeLink = Next_Node->NodeLink;
        free(Next_Node);
    }
}

int  Search_Node(struct Node *List,int Value)
{
    struct Node *TempNode = List;

    int ret_index = -1;
    int index = 0;

    while(TempNode != NULL)
    {
        if(TempNode->DataNode == Value)
        {
            ret_index = index;
        }
        TempNode = TempNode->NodeLink;
        index++;
    }
    return ret_index;
}
int Swap_Node(int *data1,int *data2)
{
    int Temp = 0;
    Temp = *data1;
    *data1 = *data2;
    *data2 = Temp;

    return Temp;
}
void Sort_List(struct Node *List)
{
    struct Node *First_Node = List;
    struct Node *Next_Node = NULL;
    int Temp = 0;
    if(NULL == List)
    {
        printf("Empty List \n");
    }
    else
    {
        while(First_Node != NULL)
        {
            Next_Node = First_Node->NodeLink;

            while(Next_Node != NULL)
            {
                 if(First_Node->DataNode > Next_Node->DataNode)
                 {
                     Swap_Node(&(First_Node->DataNode),&(Next_Node->DataNode));
                 }
                 Next_Node = Next_Node->NodeLink;
            }
            First_Node = First_Node->NodeLink;
        }
    }
}
int Max_Node(struct Node *List)
{
    struct Node *TempNode = List;
    int max = INT_MIN;
    while(NULL != TempNode)
    {
        if(TempNode->DataNode > max)
        {
            max = TempNode->DataNode;
        }
        TempNode = TempNode->NodeLink;
    }
    return max;
}

int Min_Node(struct Node *List)
{
    struct Node *TempNode = List;
    int min = INT_MAX;
    while(NULL != TempNode)
    {
        if(TempNode->DataNode < min)
        {
            min = TempNode->DataNode;
        }
        TempNode = TempNode->NodeLink;
    }
    return min;
}

void Insert_Sorted_List(struct Node *List)
{
    struct Node *TempNode = List;

    TempNode = (struct Node *) malloc(sizeof(struct  Node));

    if(NULL != TempNode)
    {
        //printf("Enter Data : ");
        //scanf("%d",&TempNode->DataNode);

        if(TempNode->DataNode >= Max_Node(TempNode))
        {
            Insert_At_end(&TempNode);
        }
        else if(TempNode->DataNode <= Min_Node(TempNode))
        {
            Insert_At_Begning(&TempNode);
        }
        else
        {
            Insert_At_After(TempNode);
        }
    }
}

void Remov_Duplicate_Node(struct Node *List)
{
    struct Node *TempNode = List;
    struct Node *Next_Node =NULL;
    struct Node *temp = NULL;

    if(TempNode == NULL)
    {
        printf("Empty List !! \n");
    }
    else
    {
        while(TempNode != NULL)
        {
            temp = List;
            Next_Node = TempNode->NodeLink;
            while(Next_Node != NULL)
            {
                if(TempNode->DataNode == Next_Node->DataNode)
                {
                    temp->NodeLink = Next_Node->NodeLink;
                }
                else
                {
                    temp = Next_Node;
                }
                Next_Node = Next_Node->NodeLink;
            }
            TempNode = TempNode->NodeLink;
        }
    }
}

void List_Of_Operation()
{
    int User_choice = 0;

    while(1)
    {

        printf("\t\t\n ----------------------------------- \n");
        printf("\t(1)-Insert_At_Begning \n");
        printf("\t(2)-Insert_At_end \n");
        printf("\t(3)-Insert_At_After \n");
        printf("\t(4)-Delete_Node_At_Beginning \n");
        printf("\t(5)-Delete_Node \n");
        printf("\t(6)-Search_Node \n");
        printf("\t(7)-Swap_Node \n");
        printf("\t(8)-Sort_List \n");
        printf("\t(9)-Insert_Sorted_List \n");
        printf("\t(10)-Remov_Duplicate_Node \n");
        printf("\t(11)-display \n");
        printf("\t(12)-Exit \n");
        printf("\t\t\n ----------------------------------- \n");

        printf("\t\t User Choice : ");
        scanf("%d",&User_choice);

        switch(User_choice)
        {
        case 1:
            Insert_At_Begning(&Head);
            break;
        case 2:
            Insert_At_end(&Head);
            break;
        case 3:
            Insert_At_After(Head);
            break;
        case 4:
            Delete_Node_At_Beginning(&Head);
            break;
        case 5:
            Delete_Node(Head);
            break;
        case 6:
            int value;
            printf("Enter Value you want Search : ");
            scanf("%d",value);
            Search_Node(Head,value);
            break;
        case 7:
            int value1,value2;
            printf("Enter Two Node you want swap : ");
            scanf("%d %d ",&value1,&value2);
            Swap_Node(&value1,&value2);
            break;
        case 8:
            Sort_List(Head);
            break;
        case 9:
            Insert_Sorted_List(Head);
            break;
        case 10:
            Remov_Duplicate_Node(Head);
            break;
        case 11:
            display(Head);
            break;
       case 12:
            printf("Quit from application \n");
            exit(1);
            break;
        default:
            printf("User Choice out of range !!\n");
            break;
        }
    }
}
