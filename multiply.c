#include<stdio.h>
#include<stdlib.h>

struct node
{
    int co,po;
    struct node *next;
};
typedef struct node *NODE;

//insert end
// display
//add_term
//multiply

NODE insert_end(NODE start,int co,int po)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->next = NULL;
    if(start==NULL)
    return temp;
    NODE current =start;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next =temp;
    return start;
}

void display(NODE start)
{
    NODE current = start;
    while(current!=NULL)
    {
        printf("%d*x^%d  ",current->co,current->po);
        current = current->next;
    }
}

NODE add_term(NODE start,int co,int po)
{
    NODE current=start,temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    if(start==NULL)
    return temp;
    while(current!=NULL)
    {
        if(current->po == po)
        {
            current->co+=co;
            return start;
        }
        current=current->next;
    }
    current = start;
    while(current->next!=NULL)
    {current=current->next;}
    current->next =temp;
    return start;
}

NODE multiply(NODE h1,NODE h2)
{
    NODE i=h1,j=h2,m;
    for(i=h1;i!=NULL;i=i->next)
    {
        for(j=h2;j!=NULL;j=j->next)
        {
            m = add_term(m,i->co*j->co,i->co+j->po);
        }
    }
    display(m);
}

int main()
{
    NODE num1=NULL,num2=NULL;
    int n,m,co,po;
    printf("Enter the number of terms in first polynomial:\n");
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        printf("Enter the co and po for the %d term\n",i);
        scanf("%d %d",&co,&po);
        num1 = insert_end(num1,co,po);
    }
    printf("First polynomial:\n");
    display(num1);
    printf("Enter the number of terms in second polynomial:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the co and po for the %d term\n",i);
        scanf("%d %d",&co,&po);
        num2 = insert_end(num2,co,po);
    }
    printf("second polynomial:\n");
    display(num2);
    printf("RESULT:\n");
    NODE res = multiply(num1,num2);
   //display(res);



}
