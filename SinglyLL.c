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
    head->nextNode=0;
    struct Node *newNode,*temp;
    temp=head;
    for(int i=1; i<size; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=A[i];
        newNode->nextNode=0;
        temp->nextNode=newNode;
        temp=newNode;
    }
}

void Display(struct Node *temp)
{
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->nextNode;
    }
    printf("\n");
}

void RecursiveDisplay(struct Node *temp)
{
    if(temp!=0)
    {
        printf("%d ",temp->data);
        RecursiveDisplay(temp->nextNode);
    }
}
void RecursiveDisplayReverse(struct Node *temp)
{
    if(temp!=0)
    {
        RecursiveDisplayReverse(temp->nextNode);
        printf("%d ",temp->data);
    }
}

int Length(struct Node *temp)
{
    int length=0;
    while(temp!=0)
    {
        length++;
        temp=temp->nextNode;
    }
    return length;
}

int RecursiveLength(struct Node *temp)
{

    if(temp==0)
        return 0;
    else
        return 1+RecursiveLength(temp->nextNode);
}

int Maxelement(struct Node *temp)
{
    int Max=0;
    while(temp)
    {
        if(temp->data > Max)
            Max=temp->data;
        temp=temp->nextNode;
    }
    return Max;
}

int RecursiveMaxelement(struct Node *temp)
{
    int Max=0;
    if(temp==0)
        return 0;

    Max=RecursiveMaxelement(temp->nextNode);
    return Max>temp->data?Max:temp->data;

}


int Sum(struct Node *temp)
{
    int sum=0;
    while(temp!=0)
    {
        sum+=temp->data;
        temp=temp->nextNode;
    }
    return sum;
}

int RecursiveSum(struct Node *temp)
{

    if(temp==0)
        return 0;
    else
        return temp->data+RecursiveSum(temp->nextNode);
}


struct Node * LinearSearch(struct Node *temp,int key)
{
    while(temp)
    {
        if(key==temp->data)
        {
            return temp;
        }
        temp=temp->nextNode;
    }
    return 0;
}

struct Node * RecursiveLinearSearch(struct Node *temp,int key)
{
    if(temp)
    {
        if(key==temp->data)
        {
            return temp;
        }
        return RecursiveLinearSearch(temp->nextNode,key);
    }

    else return 0;
}

struct Node * ImprovedLinearSearch(struct Node *temp,int key)
{
    struct Node *back;
    while(temp)
    {
        if(key==temp->data)
        {
            back->nextNode=temp->nextNode;
            temp->nextNode=head;
            head=temp;
            return temp;
        }
        back=temp;
        temp=temp->nextNode;
    }
    return 0;
}


void Insert(struct Node *temp,int position,int data)
{
    struct Node *newNode=0;
    if(position<0 || position>Length(temp))
    {
        printf("Invalid Position can't Insert Element %d\n",position);
        return;
    }
    else
    {
        newNode=( struct Node *)malloc(sizeof( struct Node));
        newNode->data=data;
        newNode->nextNode=0;
        if(position==0)
        {
            newNode->nextNode=head;
            head=newNode;
        }
        else
        {
            for(int i=0;i<position-1;i++)
                temp=temp->nextNode;

            newNode->nextNode=temp->nextNode;
            temp->nextNode=newNode;
        }
        printf("Element Inserted Successfully!!\n");
    }
}

void InsertatBegin(struct Node *temp,int data)
{
    struct Node *newNode;
    newNode=( struct Node *)malloc(sizeof( struct Node));
    newNode->data=data;
    newNode->nextNode=head;
    head=newNode;
    printf("Element Inserted Successfully!!\n");
}

void InsertatEnd(struct Node *temp,int data)
{
    struct Node *newNode=0;
    newNode=( struct Node *)malloc(sizeof( struct Node));
    newNode->data=data;
    newNode->nextNode=0;

    //finding last node of the list
    while(temp->nextNode!=0)
        temp=temp->nextNode;

    newNode->nextNode=temp->nextNode;
    temp->nextNode=newNode;
    printf("Element Inserted Successfully!!\n");
}

void SortedInsert(struct Node *temp,int data)
{
    struct Node *newNode,*back;
    newNode=(struct Node *)malloc(sizeof(struct Node ));
    newNode->data=data;
    newNode->nextNode=NULL;

    if(!head)
    {
        head=newNode;
    }
    else
    {
        while(temp && (temp->data < data))
        {
            back=temp;
            temp=temp->nextNode;
        }
        if(temp==head)
        {
            newNode->nextNode=head;
            head=newNode;
        }
        else
        {
            newNode->nextNode=back->nextNode;
            back->nextNode=newNode;
        }
    }
}


void Delete(struct Node *temp,int position)
{
    struct Node *p,*q;
    p=temp;
    q=NULL;
    if(position<1 || position>Length(temp))
    {
        printf("Invalid Index Position\n");
    }
    else
    {
        if(position==1)
        {
            q=head;
            printf("\nElement %d is deleted \n",head->data);
            head=head->nextNode;            
            free(q);
        }
        else
        {
            for(int i=0;i<position-1;i++)
            {
                q=p;
                p=p->nextNode;
            }
            printf("\nElement %d is deleted \n",p->data);
            q->nextNode=p->nextNode;
            free(p);
        }
    }
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void ReversingElements(struct Node *temp)
{
    struct Node *p;
    p=temp;
    int len=Length(temp);
    int arr[len];
    int i=0;
    while(p) 
    {
    arr[i++]=p->data;
    p=p->next;
    }
    i--;
    p=temp;
    while(p)
    {
        p->data=arr[i--];
        p=p->next;
    }
}


void Reverse(struct Node *temp)
{
    struct Node *p,*q,*r;
    p=temp;
    q=NULL;
    r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

void RecursiveReverse(struct Node *q,struct Node *p)
{
    if(p)
    {
        RecursiveReverse(p,p->next);
        p->next=q;
    }
    else
    {
        head=q;
    }
}


void isLoop(struct Node *temp)
{
    struct Node *p,*q;
    p=q=temp;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p && q && p!=q);

    if(p==q)printf("LOOP\n");
    else printf("noLOOP\n");
}

int main()
{
    int A[]= {1,1,3,4,5,6,7,8,9,10};

    printf("Creating linked list\n");
    Create(A,10);

    // printf("Using Normal function and printing Linked List\n");
    // Display(head);

    // printf("\nUsing Recursive function and printing Linked List\n");
    // RecursiveDisplay(head);

    // printf("\nUsing Recursive function and printing Reversed Linked List \n");
    // RecursiveDisplayReverse(head);

    // printf("\nLength of Linked List is %d \n",Length(head));

    // printf("\nLength of Linked List using Recursive function is %d \n",RecursiveLength(head));

    // printf("\nMax element in Linked List is %d \n",Maxelement(head));

    // printf("\nMax element in Linked List using Recursive function is %d \n",RecursiveMaxelement(head));

    // printf("\nSum of elements of Linked List is %d \n",Sum(head));

    // printf("\nSum of elements of Linked List using Recursive function is %d \n",RecursiveSum(head));

    // if(LinearSearch(head,55))
    //     printf("\nElement %d found",LinearSearch(head,55)->data);
    // else
    //     printf("\nElement not found\n");


    // if(RecursiveLinearSearch(head,10))
    //     printf("\nElement %d found using RecursiveLinearSearch\n",RecursiveLinearSearch(head,10)->data);
    // else
    //     printf("\nElement not found RecursiveLinearSearch\n");

    // if(ImprovedLinearSearch(head,2))
    //     printf("\n%d Element found",ImprovedLinearSearch(head,2)->data);
    // else
    //     printf("\nElement not found\n");
    // Display(head);

    // Insert(head,0,11);
    // Insert(head,3,12);
    // Insert(head,15,11);
    // InsertatBegin(head,69);
    // InsertatEnd(head,69);
    // SortedInsert(head,-1);
    // Display(head);
    // Delete(head,5);
    // Delete(head,0);
    // Delete(head,50);
    Display(head);
    ReversingElements(head);
    Display(head);
    Reverse(head);
    Display(head);
    RecursiveReverse(NULL,head);
    Display(head);
    RemoveDuplicate(head);
     Display(head);


    return 0;
}
