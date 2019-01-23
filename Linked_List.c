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

    while(current->next != NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

void getData(node *head)
{
    node *current = head;

    while(current->next != NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}

void DeleteNodeFromLinkedList(node **head,int position)
{
    int k=1,positon=0;
    node *p,*q;
    if(*head==NULL)
    {
        printf("List Empty");
        return;
    }
    p=*head;
    if(positon=1)
    {
        *head=(*head)->next;
        free(p);
        return;
    }
    else
    {
        while((p!=NULL) && (k<positon))
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL)
            printf("position does not exist");
        else
        {
            q->next=p->next;
            free(p);
        }
    }
}

void DeleteLinkedList(node **head)
{
    node *auxilaryNode,*iterator;
    iterator=*head;
    while(iterator)
    {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
        *head = NULL;
    }
}

int main()
{
    int c=0,data=0,position=0,loop=1;

    node *Head;
    Head = (node *)malloc(sizeof(node));
    Head -> next = NULL;

    while(loop)
    {
        printf("[1]insert\n[2]count\n[3]print\n[4]delete\n[5]delete linkedlist\n>");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter the data : ");
            scanf("%d",&data);
            printf("enter the position : ");
            scanf("%d",&position);
            InsertInLinkedList(&Head,data,position);
            printf("\n");
            break;

        case 2:
            printf("count : %d\n\n",ListLength(Head));
            break;

        case 3:
            printf("List : ");
            getData(Head);
            printf("\n\n");
            break;

        case 4:
            printf("List : ");
            getData(Head);
            printf("\nenter the position of the element : ");
            scanf("%d",&position);
            DeleteNodeFromLinkedList(&Head,position);
            printf("List after deletion : ");
            getData(Head);
            printf("\n\n");
            break;

        case 5:
            DeleteLinkedList(&Head);
            printf("LinkedList successfully deleted\n\n");
            break;

        default:
            printf("Wrong input.Try again!\n\n");
            break;
        }

        printf("Do you want to continue?[1,0] : ");
        scanf("%d",&loop);
    }
}
