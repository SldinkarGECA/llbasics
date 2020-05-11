#include<stdio.h>
#include<stdlib.h>
#define nextNode next

struct Node
{
    int data;
    struct Node *nextNode;
} *head;

void Create(int A[],int size)
{
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->nextNode=head;
    struct Node *newNode,*temp;
    temp=head;
    for(int i=1; i<size; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=A[i];
        newNode->nextNode=head;
        temp->nextNode=newNode;
        temp=newNode;
    }
}

void Display(struct Node *temp)
{
    static int flag=0;
    while(temp!=head || flag==0)
    {
        flag=1;
        printf("%d ",temp->data);
        temp=temp->nextNode;
    }
    printf("\n");
    flag=0;
}

int Length(struct Node *temp)
{
     int len=0;
    do
    {
        len++;
        temp=temp->nextNode;
    }while(temp!=head);
    return len;
}

void Insert(struct Node *temp,int position, int data)
{
    struct Node *newNode;
    if(position<0 || position>Length(temp))
    {
        printf("NO SUCH INDEX FOUND\n");
        return;
    }
    if(position==0)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=data;
        if(head==NULL)
        {
            head=newNode;
            head->next=head;
        }
        else
        {
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
            head=newNode;
        }
    }
    else
    {
        for(int i=0;i<position-1;i++)
        {
            temp=temp->next;
        }
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=data;

        newNode->next=temp->next;
        temp->next=newNode;
    }
}


void Delete(struct Node *temp,int position)
{
    struct Node *p;
    p=head;
    if(position <1 || position>Length(temp))
    {
        printf("NO SUCH INDEX FOUND\n");
        return;
    }

    if(position==1)
    {
        while(p->next!=head)
            p=p->next;

        if(p==head)
        {
            printf("%d value deleted\n",head->data);
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            printf("%d value deleted\n",head->data);
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(int i=0;i<position-2;i++)
        {
            p=p->next;
        }
        struct Node *q;
        q=p->next;
        p->next=q->next;
        printf("%d value deleted\n",q->data);
        free(q);
    }

}


int main()
{
    int A[]= {1,2,3,4,5,6,7,8,9,10};

    printf("Creating linked list\n");
    Create(A,10);
    printf("%d\n",Length(head));
    Insert(head,0,11);
    Insert(head,11,12);
    Display(head);
    Delete(head,0);
    Display(head);
    printf("%d\n",Length(head));

    return 0;
}
