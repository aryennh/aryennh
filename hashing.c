#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//insertion
//deletion
//search

int hash_table[SIZE];

void insertion(int key)
{
    int h,flag=0;
    for(int i=0;i<SIZE;i++)
    {
        h=(key+i)%SIZE;
        if(hash_table[h]==-1)
        {
            hash_table[h] =key;
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        printf("FULL BRUH\n");
    }
}

void deletion(int key)
{
    int h,flag=0;
    for(int i=0;i<SIZE;i++)
    {
        h =(key+i)%SIZE;
        if(hash_table[h]==key)
        {
            hash_table[h] =-1;
            flag= 1;
            break;
        }
    }
}

int search(int key)
{
    int h,flag=0;
    for(int i=0;i<SIZE;i++)
    {
        h=(key+i)%SIZE;
        if(hash_table[h]==key)
        {
            flag= 1;
            return h;
        }
    }
    if(flag==0)
    return -1;
}

void display()
{
    
    for(int i=0;i<SIZE;i++)
    {
        
        printf("%d\t%d\n",i,hash_table[i]);
    }
    printf("\n\n");
}

int main()
{
    int choice;
    int item;
    for(int i=0;i<SIZE;i++)
    {
        hash_table[i] =-1;
    }
    display();
    for(;;)
    {
        printf("1.Insertion \n 2.Deletion\n 3.Search \n 4.Displayn\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the elemtn to be inserted\n");
                    scanf("%d",&item);
                    insertion(item);
                    break;
            case 2: printf("enter elemetn to be deleted\n");
                    scanf("%d",&item);
                    deletion(item);
                    break;
            case 3: printf("Enter e;ement to be seadch:\n");
                    scanf("%d",&item);
                    if(search(item)==-1)
                    printf("El not found\n");
                    else
                    {
                        printf("elemt fond at %d",search(item));
                    }
                    break;
            case 4:
                    display();
                    break;
            default:break;
        }
    }
}