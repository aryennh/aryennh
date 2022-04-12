#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void heapify(int a[],int n)
{
    int i,j,k,v,flag=0;
    for(i=n/2;i>=1;i--)
    {
        v=a[i];
        while(!flag && 2*i<=n)
        {
            j=2*i;
            if(j<n && a[j]>a[j+1])
            {
                j=j+1;
            }
            if(v>a[j])
            {
                a[i] =a[j];
                i=j;
            }
            else
                flag=1;
        }
        flag=0;
        a[i] =v;
    }
}

int main()
{
    int choice,arr[20],n,item;
    printf("Enter the number of elements in the heap");
    scanf("%d",&n);
    printf("Enter the elements in the array:\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapify(arr,n);
    //printf("Elements after heapify:\n");
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d",arr[i]);
    // }
    for(;;)
    {
        printf("\n1.Insert\n2.Delete\n3.display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element to be inserted:\n");
                    scanf("%d",&item);
                    if(n==20)
                        printf("Priority Queue is full already,first delete something\n");
                    else
                    {
                        n++;
                        arr[n] = item;
                        heapify(arr,n);
                    }
                    break;
            case 2: if(n>=1)
                    {
                        printf("Element deleted is:%d\n",arr[1]);
                        arr[1]= arr[n];
                        n--;
                        heapify(arr,n);
                    }
            case 3: printf("Elements after heapify:\n");
                    for(int i=1;i<=n;i++)
                    {
                        printf("%d\t",arr[i]);
                    }
        }
    }
}