#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//circular linked list with header node
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;

//insert end
//insert begin
//display
//add zeroes
//reverse
// add

NODE insert_end(NODE head,int item)
{
    NODE current,temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data =item;
    if(head==head->addr)
    {
        temp->addr =head;
        head->addr =temp;
        return head;
    }
    current = head->addr;
    while(current->addr !=head)
    {
        current = current->addr;
    }
    current->addr = temp;
    temp->addr =head;
    return head;
}

NODE insert_begin(NODE head,int item)
{
    NODE current,temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data =item;
    if(head==head->addr)
    {
        head->addr = temp;
        temp->addr = head;
        return head;
    }
    temp->addr = head->addr;
    head->addr =temp;
    return head;
}

void display(NODE head)
{
    NODE current=head->addr;
    while(current->addr!=head)
    {
        printf("%d ",current->data);
        current=current->addr;
    }
    printf("%d ",current->data);
    printf("\n\n");
}

NODE reverse(NODE head)
{
    NODE current = head->addr,prev=head;
    NODE next;
    while(current!=head)
    {
        next=current->addr;
        current->addr = prev;
        prev =current;
        current =next;
        head->addr =prev;
    }
    return head;
}

void add(NODE num1,NODE num2)
{
    NODE temp1,temp2;
    temp1=num1;
    temp2=num2;
    NODE res=malloc(sizeof(struct node));
    res->addr = res;
    temp1=reverse(temp1);
    temp1=temp1->addr;
    temp2 = reverse(temp2);
    temp2=temp2->addr;
    int sum,carry=0,x;
    while(temp1!=num1 && temp2!=num2)
    {
        x = temp1->data + temp2->data +carry;
        sum=x%10;
        carry = x/10;
        res=insert_begin(res,sum);
        temp1=temp1->addr;
        temp2=temp2->addr;
    }
    //printf("DAMN");
    if(carry>0)
    {
        res=insert_begin(res,carry);
    }
    display(res);
    printf("\n\n");
}

int main()
{
    NODE num1,num2;
    num1=(NODE)malloc(sizeof(struct node));
    num2=(NODE)malloc(sizeof(struct node));
    num1->addr =num1;
    num2->addr =num2;
    char first[20],second[20];
    printf("Enter the first number:\n");
    scanf("%s",first);
    int l1 = strlen(first);
    for(int i=0;first[i]!='\0';i++)
    {
        num1 = insert_end(num1,first[i]-'0');
    }
    printf("Enter the second number:\n");
    scanf("%s",second);
    int l2 = strlen(second);
    for(int i=0;second[i]!='\0';i++)
    {
        num2 = insert_end(num2,second[i]-'0');
    }
    if(l1>l2)
    {
        for(int j=0;j<l1-l2;j++)
        {
            num2 = insert_begin(num2,0);
        }
    }
    else
    {
        for(int j=0;j<l2-l1;j++)
        {
            num1 = insert_begin(num1,0);
        }
    }
    printf("\nFirst number is:\n");
    display(num1);
    printf("\nSecond number is\n");
    display(num2);
    printf("Addition of the two numbers is:\n");
    add(num1,num2);
}