
//#define SINGLR_LINKED_LIST.H

#include <stdio.h>
#include <stdlib.h>
#include"PlatForm_Types.h"

struct Node
{
    int DataNode;
    struct Node *NodeLink;
};

void Insert_At_Begning(struct Node **List);
void Insert_At_end(struct Node **List);
void Insert_At_After(struct Node *List);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node(struct Node *List);
int  Search_Node(struct Node *List,int Value);
int Swap_Node(int *data1,int *data2);
void Sort_List(struct Node *List);
int Max_Node(struct Node *List);
int Min_Node(struct Node *List);
void Insert_Sorted_List(struct Node *List);
void Remov_Duplicate_Node(struct Node *List);
int Get_Length(struct Node *List);
void display(struct Node *list);

