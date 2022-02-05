#include <stdio.h> 
#include<stdlib.h>
# define max 6  
int queue[max];
int front=-1;  
int rear=-1;  
void enqueue();
void dequeue();
void display();
void peek();
void enqueue()  
{  
        int item;
        printf("Enter the item");
        scanf("%d",&item);
        if(front==-1 && rear==-1) 
        {  
            front=0;  
            rear=0;  
            queue[rear]=item;  
        }  
        else if((rear+1)%max==front) 
        {  
            printf("overflow");  
        }  
        else  
        {  
            rear=(rear+1)%max;       
            queue[rear]=item; 
        }  
        printf("%d is inserted",item);
    }  
      
void dequeue()  
    {  
    if((front==-1) && (rear==-1))
    {  
        printf("\nunderflow");  
    }  
    else if(front==rear)  
    {  
       printf("\n%d is deleted", queue[front]);  
       front=-1;  
       rear=-1;  
    }   
    else  
    {  
       printf("\n%d is deleted", queue[front]);  
       front=(front+1)%max;  
    }  
    }   
void display()  
    {  
        int i=front;  
        if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty");  
        }  
        else  
        {  
            printf("\nThe Elements are :");  
            while(i<=rear)  
            {  
                printf("%d\t", queue[i]);  
                i=(i+1)%max;  
            }  
        }  
    }
void peek()
{
    if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty");  
        }  
    else
    {
        printf("The peek element is %d",queue[front]);
    }
    
}
void main()  
    {  
        int choice=1;
        while(choice!=5)
        {  
        printf("\n1.Insert an element");  
        printf("\n2 Delete an element");  
        printf("\n3.Display the element");  
        printf("\n4.peek element");
        printf("\n4.Exit");
        printf("\nEnter your choice");  
        scanf("%d", &choice);  
          
        switch(choice)  
        {  
              
            case 1:  
                 enqueue();  
                 break;  
            case 2:  
                 dequeue();  
                 break;  
            case 3:  
                 display();  
                 break;
            case 4:
                 peek();
                 break;
            case 5:
                 exit(0);
                 break;
            default:
                 printf("invalid entry");
      
        }
        }  
    }  