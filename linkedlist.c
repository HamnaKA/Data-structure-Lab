#include<stdio.h>
#include<stdlib.h>
int beginsert();
int begdelete();
int lastinsert();
int traverse();
int posinsert();
int display();
int search();
int posdelete();

struct node
{
    int data;
    struct node *link;
    
};
struct node *head;

int beginsert()
{
    struct node *ptr;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\n List is empty");
    }
    else
    {
    printf("\nEnter the element to be inserted:");
    scanf("%d",&item);
    ptr->data=item;
    ptr->link=head;
    head=ptr;
    printf("%d is inserted at the beginning",item);
    }
}
int begdelete()
{
    struct node *ptr;
    if(head==NULL)
       printf("The list is empty");
    else
    {
        ptr = head;  
        head = ptr->link;  
        free(ptr);  
        printf("\nNode from beginning is deleted\n"); 
    }
   
    
}
int traverse()
{
    int count=0;
    struct node *ptr=NULL;
    ptr=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else{
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("\nThe total Number of elements are %d",count);
    }
}
int lastinsert()
{ 
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> link = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> link!= NULL)  
            {  
                temp = temp -> link;  
            }  
            temp->link = ptr;  
            ptr->link = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  

int lastdelete()
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> link == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\n Node deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->link != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->link;  
        }  
        ptr1->link = NULL;  
        free(ptr);  
        printf("\nNode deleted\n");  
    }     
}  
int posinsert()
{
  int loc,i,item;
  struct node *ptr,*temp;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
    printf("UNDERFLOW");
  }
  printf("\nEnter the location:\n");
  scanf("%d",&loc);
    temp=head;
    for(i=1;i<loc-1;i++)
    {
      temp=temp->link;
      if(temp==NULL)
      {
        printf("\nThere is less than %d elements\n",loc);
      }
    }
        printf("enter the data:");
        scanf("%d",&item);
        ptr->data=item;
        ptr->link=temp->link;
        temp->link=ptr;
        printf("\nNode Inserted\n");
}
int search()
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item to search:\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> link;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
} 
int display()
{
  struct node *ptr;
  ptr=head;
  if(ptr == NULL)  
  {  
    printf("\nEmpty List\n");  
  } 
  else
  {
  while(ptr!=NULL)
  {
    printf("%d\t",ptr->data);
    ptr=ptr->link;
  }
  }
}
int posdelete()
{
    int i,pos;
    struct node *ptr;
    printf("enter the position:");
    scanf("%d",&pos);
    ptr=head;
    for(i=0;i<pos-1;i++)
    {
     ptr=ptr->link;
    }
    ptr->link=ptr->link->link;  
    printf("the deleted element is %d",ptr->data);
}
void main()  
{  
int choice =0;  
    while(choice != 30)  
    {    
        printf("\n1.Insert in begining\n2.Delete from beggining\n3.Traverse\n4.Delete from beggining\n5.last insert\n6.last delete\n7.insert specific position\n8.display\n9.search\n10.pos delete");  
        printf("\nEnter your choice?\n\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                     beginsert();  
                     break;  
            case 2: 
                     begdelete();
                     break;
            case 3: 
                     traverse();
                     break;
            case 4:  begdelete();
                     break;
            
            case 5:
                    lastinsert();
                     break;
                     
            case 6: 
                     lastdelete();
                     break;
            case 7: 
                     posinsert();
                     break;
            case 8:
                     display();
                     break;
            case 9:
                     search();
                     break;
            case 10:
                     posdelete();
                     break;
            
            default:
                     printf("invalid entry");  
        }
   }
}