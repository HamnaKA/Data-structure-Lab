#include<stdio.h>
#include<stdlib.h>
void insertbeg();
void display();
void insertend();
void deletebeg();
void deleteend();
void posinsert();
void posdelete();
void search();
struct node
{
 int data;
 struct node *next;
 struct node *prev;
};
struct node *head;
void insertbeg()
{
  int item;
  struct node *ptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
    printf("\noverflow\n");
  }
  else
  {
    printf("\nEnter the data:\n");
    scanf("%d",&item);
    if(head==NULL)
    {
       ptr->next=NULL;
       ptr->prev=NULL;
       ptr->data=item;
       head=ptr;
    }
    else
    {
       ptr->data=item;
       ptr->prev=NULL;
       ptr->next=head;
       head->prev=ptr;
       head=ptr;
    }
    printf("Node Inserted");
  }
}
void display()
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
    ptr=ptr->next;
  }
  }
}
 
void insertend()
{
  int item;
  struct node *ptr,*temp;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
    printf("overflow");
  }
  else
  {
    printf("enter the data:");
    scanf("%d",&item);
    ptr->data=item;
     if(head==NULL)
    {
       ptr->next=NULL;
       ptr->prev=NULL;
       head=ptr;
    }
    else
    {
       temp=head;
       while(temp->next!=NULL)
       {
            temp=temp->next;
       }
     temp->next=ptr;
     ptr->next=NULL;
     ptr->prev=temp;
    }
 }
}
void deletebeg()
{
  struct node *ptr;
  if(head==NULL)
  {
      printf("Underflow");
  }
  else if(head->next==NULL)
  {
    head=NULL;
    free(head);
    printf("\nNode deleted\n");
  }
  else
  {
     ptr=head;
     head=head->next;
     free(head->prev);
     head->prev=NULL;
     printf("\nNode deleted\n");
  }
}
void deleteend()
{
  struct node *ptr;
  if(head==NULL)
  {
      printf("overflow");
  }
  else if(head->next==NULL)
  {
    head=NULL;
    free(head);
    printf("\nNode deleted\n");
  }
 else
 {
    ptr=head;
    while(ptr->next!=NULL)
    {
       ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    printf("\nNode deleted\n");
 }
}
void posinsert()
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
  if (loc==1)
  {    
       printf("\nenter the data:\n");
       scanf("%d",&item);
       ptr->data=item;
       ptr->prev=NULL;
       ptr->next=head;
       head->prev=ptr;
       head=ptr;
  }
  else
  {  
    temp=head;
    for(i=1;i<loc-1;i++)
    {
      temp=temp->next;
      if(temp==NULL)
      {
        printf("\nThere is less than %d elements\n",loc);
      }
    }
        printf("enter the data:");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next=ptr;
        temp->next->prev=ptr;
        printf("\nNode Inserted\n");
  }
}
void posdelete()
{
   struct node *ptr;
   int loc,i;
   printf("enter the position:");
   scanf("%d",&loc);
  if (head == NULL || loc<=0)
        printf("empty list");
  ptr=head;
  for (int i = 1; ptr != NULL && i < loc; i++)
        ptr = ptr->next;
  if (ptr == NULL)
        printf("Not possible");
  if (head == NULL || ptr == NULL)
        printf("Not possible");
  if (head== ptr)
        head = ptr->next;
  if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
  if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
  free(ptr);
}
void search()  
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
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
} 


void main()  
{  
int choice =0;  
    while(choice != 30)  
    {    
        printf("\n1.Insert in begining\n2.Display\n3.Insert at end\n4.Delete from beggining\n5.delete from end\n6.Insert at specified postion\n7.Delete from a given position\n8.Search");  
        printf("\nEnter your choice?\n\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                     insertbeg();  
                     break;  
            case 2: 
                     display();
                     break;
            case 3: 
                     insertend();
                     break;
            case 4: 
                     deletebeg();
                     break;
            case 5: 
                     deleteend();
                     break;
            case 6: 
                     posinsert();
                     break;
            case 7:
                     posdelete();
                     break;
            case 8: 
                     search();
                     break;
            default:
                     printf("invalid entry");  
        }
   }
}