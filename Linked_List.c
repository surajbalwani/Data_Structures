#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}node;

void InsertInLinkedList(node **head,int data,int position)
{
    int k=1;
    struct ListNode *p,*q,*newNode;

    newNode=(node *)malloc(sizeof(node));

    if(!newNode)
    {
        printf("memory error");
        return;
    }

    newNode->data = data;
    p=*head;

    if(position == 1)
    {
        newNode->next = p;
        *head=newNode;
    }
    else
    {
        while((p!=NULL)&&(k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        q->next=newNode;
        newNode->next=p;
    }
}

int ListLength(node *head)
{
    node *current = head;
    int count=0;

    while(current != NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

int main()
{
    int c=0;

    node *Head;
    Head = (node *)malloc(sizeof(node));
    Head -> next = NULL;

    InsertInLinkedList(&Head,15,1);
    InsertInLinkedList(&Head,20,1);

    printf("count : %d",ListLength(Head));
}
