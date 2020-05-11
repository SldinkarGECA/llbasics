#include<stdio.h>
#include<stdlib.h>
#define nextNode next

struct Node
{
    int data;
    struct Node *nextNode;
} *first=NULL,*second=NULL,*third=NULL;

void Createfirst(int A[],int size)
{
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->nextNode=NULL;
    struct Node *newNode,*temp;
    temp=first;
    for(int i=1; i<size; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=A[i];
        newNode->nextNode=NULL;
        temp->nextNode=newNode;
        temp=newNode;
    }
}


void Createsecond(int A[],int size)
{
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->nextNode=NULL;
    struct Node *newNode,*temp;
    temp=second;
    for(int i=1; i<size; i++)
    {
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=A[i];
        newNode->nextNode=NULL;
        temp->nextNode=newNode;
        temp=newNode;
    }
}


void Display(struct Node *temp)
{
    while(temp!=NULL) 
    {
        printf("%d ",temp->data);
        temp=temp->nextNode;
    }
    printf("\n");
}


void Concate(struct Node *p,struct Node *q)
{
    third=p;
    while(p->next) 
    {
        p=p->next;
    }
    p->next=q;
}

void Merge(struct Node *p,struct Node *q)
{
    
    struct Node *last=NULL,;
       if(p->data < q->data)
       {
            third=last=p;            
            p=p->next;
            last->next=NULL;
       }
       else
       {
            third=last=q;  
            q=q->next;
            last->next=NULL;
       }

        while(p && q)
       {
            if(p->data < q->data)
           {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
           }
           else
           {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;    
           }       
       }
            if(q)
           {
            last->next=q;
           }
           else
           {
            last->next=p;
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
    int A[]= {1,3,5,7,10};
    int B[]= {2,4,6,8,9};

    printf("Creating linked list\n");
    Createfirst(A,5);

    printf("Creating linked list\n");
    Createsecond(B,5);

    Display(first);
    Display(second);

    Concate(first,second);
    Display(third);



    Merge(second,first);
    // Display(third);
    isLoop(third);

    return 0;
}

//hackerrank solution
// SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
// {
//     if(head1==NULL)
//     return head2;
//     else if(head2==NULL){
//     return head1;
//     }
// SinglyLinkedListNode *third=NULL,*last=NULL;
//     if(head1->data<head2->data)
//     {
//         third=head1;
//         last=head1;
//         head1=head1->next;
//         last->next=NULL;
//     }
//     else
//     {
//         third=head2;
//         last=head2;
//         head2=head2->next;
//         last->next=NULL;
//     }

//     while(head1 && head2)
//     {
//        if(head1->data<head2->data)
//         {
//             // third=head1;
//             last->next=head1;
//             last=head1;
//             head1=head1->next;
//             last->next=NULL;
//         }
//         else
//         {
//             // third=head2;
//             last->next=head2;
//             last=head2;
//             head2=head2->next;
//             last->next=NULL;
//         } 
//     }

//     if(head1)
//     last->next=head1;
//     else
//     last->next=head2;





// return third;

// }
