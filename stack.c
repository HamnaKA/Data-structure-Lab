#include<stdio.h>
#include<conio.h>
int stack[100];
int i,j,n;
int choice=0;
int top=-1;
int push();
int pop();
int show();
int topp();
int main()
{
    printf("enter the elements in stack:");
    scanf("%d",&n);
    while(choice != 4)
    {
    printf("choose the stack operation to be performed");
    printf("\n1.Push\n2.Pop\n3.show\n4.Top\n");
    printf("enter Your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        show();
        break;
    case 4:
        topp();
        break;
    default:
        printf("Invalid entry");
        break;
    };
    }
    return 0;
}
int push()
{
    int val;
    if(top==n)
    {
        printf("\n overflow");
    }
    else
    {
        printf("enter the value:");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;

    }
}
int pop()
{
    if(top==-1)
    {
        printf("\n underflow");
    }
    else
    {
       top=top-1;
    }
}
int show()
{
   
   if (top==-1)
   {
       printf("stack is empty");
   }
   else
   {
       for ( i = top; i >=0; i--)
       {
       printf("%d\n",stack[i]);
       }
   }
   
}
int topp()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
       printf("%d",stack[top]);
    }
}
