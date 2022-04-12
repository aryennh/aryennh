#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

//create bst
//traversals
//delete
//inorder_successor

NODE create_bst(NODE root,int item)
{
    NODE cur=root;
	NODE prev;
	NODE temp = malloc(sizeof(struct node));
	temp->data = item;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	return temp;
	while(cur!=NULL)
	{
		prev=cur;
		if(item < cur->data)
		{
			cur=cur->left;
		}
		else
		{
			cur =cur->right;
		}
	}
	if(item < prev->data)
		prev->left=temp;
	else
		prev->right=temp;
	return root;
}


int inorder_successor(NODE root)
{
    NODE current=root;
    while(current->left=NULL)
    {
        current=current->left;
    }
    return current->data;
}

NODE delete(NODE root,int item)
{
    NODE temp;
    if(item<root->data)
    root->left = delete(root->left,item);
    else if(item>root->data)
    {
    root->right = delete(root->right,item);
    }
    else
    {
        if(root!=NULL && root->right==NULL && root->left==NULL)
        {
            root= NULL;
        }
        else if(root->right==NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
        }
        else if(root->left==NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
        }
        else
        {
            int x =inorder_successor(root->right);
            root->data = x;
            root->right = delete(root->right,x);
        }
    }
    return root;
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main()
{
    NODE root=NULL;
    int choice,item;
    for(;;)
    {
        printf("\n1.Insert\n2.Delete\n3.Inorder\n Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    printf("\nEnter element to be inserted: ");
                    scanf("%d",&item);
                    root = create_bst(root,item);
                    break;
            case 2:
                    printf("Enter element to be deleted:");
                    scanf("%d",&item);
                    root =delete(root,item);
                    break;
            case 3:printf("inorder traversal is:\n");
                   inorder(root);
                   break;
            default :break;
        }
    }
}