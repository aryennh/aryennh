#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20


struct stack
{
    int top;
    char data[20];
};
typedef struct stack STACK;

void push( STACK *S, char item)
{
	if(S->top==SIZE-1)
	{
		printf("\nStack Overflow\n");
	}
	else
	{
		S->data[++S->top]=item;
	}
}

char pop(STACK *s)
{
    return s->data[s->top--];
    
}

int preced(char symbol)
{
    switch(symbol)
    {
        case '^':return 5;
        case '*':return 3;
        case '/':return 3;
        case '+':return 1;
        case '-':return 1;
    }
}

void infix_to_postfix(STACK *S,char a[20])
{
    // char postfix[20],symbol;
    // int i;
    // int j=0;
    // for(i=0;infix[i]!='\0';i++)
    // {
    //     symbol = infix[i];
    //     if(isalnum(symbol))
    //         postfix[j++] = symbol;
    //     else
    //     {
    //         //printf("ASDASD");
    //         if(s->top==-1)
    //         {
    //             //printf("\nAWWWWWW");
    //             push(s,symbol);
    //         }
    //         // if(symbol=='(')
    //         // {
    //         //     push(s,symbol);
    //         // }
    //         // else if(symbol==')')
    //         // {
    //         //     t=pop(s);
    //         //     while(t!='(')
    //         //     {
    //         //         postfix[j++] = pop(s);
    //         //     }
    //         //     pop(s);
    //         // }
    //         if(preceed(symbol)> preceed(s->data[s->top]) && s->top!=-1)
    //         {
    //             push(s,symbol);
    //             printf("\n%d\n",s->top);
    //         }
    //         else
    //         {
    //             while(preceed(symbol)<=preceed(s->data[s->top]))
    //             {
    //                     postfix[j++] =pop(s);
    //                     printf("\n%d\n",s->top);

    //             }

    //         }
    //     }
        
    // }
    // //printf("%d",s->top);
    // while(s->top!=-1)
    //         {
    //             postfix[j++] = pop(s);
    //         }
    // //printf("Postfix expression is:\n");
    // postfix[j++] = '\0';
    // printf("\nPostfix Expression is : %s\n\n",postfix);
    char postfix[SIZE];
	int i,j=0;
	char sym;
	for(i=0;a[i]!='\0';i++)
	{
		sym=a[i];
		if(isalnum(sym))
			postfix[j++]=sym;
		else if(S->top==-1)
			push(S,sym);
		else if(sym=='(')
			push(S,sym);
		else if(sym==')')
		{
			char t=pop(S);
			while(t!='(')
			{
				postfix[j++]=t;
				t=pop(S);
			}
		}
		else 
		{
			if( S->top!=-1 && S->data[S->top]!='(' && preced(sym)<=preced(S->data[S->top]) )
			{
				postfix[j++]=pop(S);
			}
			push(S,sym);
		}
		
	}
	while(S->top!=-1)
	postfix[j++]=pop(S);
	postfix[j++]='\0';
	printf("\nPostfix Expression is : %s\n\n",postfix);
}

int main()
{
    STACK S;
    S.top=-1;
    char infix[20];
    printf("Enter the infix expression:\n");
    int i;
    scanf("%s",infix);
    printf("infix:%s",infix);
    infix_to_postfix(&S,infix);
    return 42;
}