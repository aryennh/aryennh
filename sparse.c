#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node
{
    int data,row,col;
    struct node *prev;
    struct node *next;
};
typedef struct node *NODE;

//insert_end
//display
//display_matrix

NODE insert_end(NODE start,int row,int col,int item)
{
    NODE temp = malloc(sizeof(struct node));
    temp->data = item;
    temp->row =row;
    temp->col =col;
    temp->next = NULL;
    temp->prev = NULL;
    if(start==NULL)
    return temp;
    NODE current = start;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next= temp;
    temp->prev =current;
    return start;
}

void display(NODE start)
{
    NODE temp;
    temp = start;
    printf("row\tcol\tdata\n");
    while(temp!=NULL)
    {
        printf("%d\t%d\t%d\n",temp->row,temp->col,temp->data);
        temp=temp->next;
    }
}

void display_matrix(NODE start,int m,int n)
{
    int i,j;
    NODE temp=start;
    printf("\n\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp!=NULL && temp->row==i && temp->col == j)
            {
                printf("%d\t",temp->data);
                temp =temp->next;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
    //only print non zero values
}

int main()
{
    int e,m,n,i,j;
    NODE l = NULL;
    printf("Enter the numer of rwos and voclsn\n");
    scanf("%d %d",&m,&n);
    printf("\nEnter the elements in the matrix\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&e);
            if(e!=0)
            {
                l=insert_end(l,i,j,e);
            }
        }
    }
    display(l);
    display_matrix(l,m,n);
}
