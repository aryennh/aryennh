#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5;

struct queue
{
    int r,f;
    char message[5][20];
};
typedef struct queue QUEUE;

//enqueue
//dequeue
//display

void enqueue(QUEUE *q,char item[20])
{
    q->r=(q->r+1)%5; 
    strcpy(q->message[q->r],item);
    if(q->f==-1)
        q->f=0;
}

void dequeue(QUEUE *q)
{
    char e[20];
    if(q->r==q->f)
    {
        strcpy(e,q->message[q->f]);
        q->f=-1;
        q->r=-1;
    }
    else
    {
        strcpy(e,q->message[q->f]);
        q->f =(q->f+1)%5;
    }
    printf("%s",e);
}

void display(QUEUE q)
{
    while(q.f!=q.r)
    {
        printf("%s\t",q.message[q.f]);
        q.f = (q.f+1)%5;
    }
    printf("%s\t",q.message[q.f]);

}

int main()
{
    QUEUE q;
    q.r=-1;
    q.f=-1;
    int choice;
    char message[20];
    for(;;)
    {
        printf("1.message\n2.delete\n3.display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Put message pls\n");
                   scanf("%s",message);
                   enqueue(&q,message);
                   break;
            case 2:printf("Message is:\n");
                   dequeue(&q);
                   break;
            case 3:display(q);
                   break;
        }
    }
}



