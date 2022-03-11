
#include <stdio.h>
#include<stdlib.h>

struct node 
{   
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
void insertatbeg();
void insertinbetween();
void insertatend();
void deleteatend();
void deleteatbeg();
void search();
void createlist();
void display();

void main()

{
    int choice;
    while(1)
    {
        printf("\n enter your choice:");
        printf("\n 1.create list \n 2.enter at the beginning \n 3.enter at the end \n 4.enter after an element \n 5.delete from the beginning \n 6.delete from the end \n 7.Search \n 8.display\n9.exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:createlist();
                  break;
            case 2:insertatbeg();
                  break;
            case 3:insertatend();
                  break;
            case 4:insertinbetween();
                  break;
            case 5:deleteatbeg();
                break;
            case 6:deleteatend();
                break; 
            case 7:search();
                break; 
            case 8:display();
                break;  
            case 9:exit(1);
                 break;
 
            default:printf("\n invalid choice");
        }
    }
}

void createlist()
{
  struct node *tmp,*q;
  int item;
  tmp = (struct node *)malloc(sizeof(struct node));
  printf("\n enter the elements to be inserted:");
  scanf("%d",&item);
  tmp->data=item;
  tmp->next = NULL;
  tmp->prev = NULL;
  
  if(start == NULL)
  {
      start = tmp;
  }
  else
  {
      q= start;
      while(q->next!=NULL)
      q=q->next;
      q->next = tmp;
      tmp->prev = q;
  }
}


void display()
{
  struct node *q;
  if(start == NULL)
  printf("\n list is empty");
  else
  {
      printf("\n list elements are:");
      q=start;
      while(q!=NULL)
      {
          printf("\n %d",q->data);
          q=q->next;
      }
  }
  
}

void insertatbeg()
{
    int item;
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the item to be inserted:");
    scanf("%d",&item);
    tmp->data=item;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(start == NULL)
    printf("\nlist is empty");
    else
    {
        tmp->next=start;
        tmp->prev = NULL;
        start = tmp;
        printf("\n element inserted");
    }
    
}

void insertatend(){
    int item;
    struct node *tmp,*q;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the item to be inserted:");
    scanf("%d",&item);
    tmp->data=item;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(start == NULL)
    printf("\nlist is empty");
    else
    {
      q=start;
      while(q->next!=NULL)
      q=q->next;
      tmp->prev=q;
      q->next=tmp;
      tmp->next=NULL;
      printf("\n element inserted");
    }
}

void insertinbetween()
{
    int item,after;
    struct node *tmp,*q;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the item to be inserted:");
    scanf("%d",&item);
    printf("\n enter the element after which this is to be inserted");
    scanf("%d",&after);
    tmp->data=item;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(start == NULL)
    printf("\nlist is empty");
    else
    {
        q=start;
        while(q!=NULL)
        {
          if(q->data == after)
          {
            tmp->next=q->next;
            q->next=tmp;
            tmp->prev=q;
            printf("\n element inserted");
            break;
          }
          q=q->next;
        }
    }
}

void deleteatbeg()
{
    struct node *tmp;
    if(start == NULL)
    printf("\nlist is empty");
    else
    {
       tmp = start;
       start = start->next;
       start->next->prev = NULL;
       printf("\n deleted element is %d",tmp->data);
       free(tmp);
       
       
    }
}

void deleteatend()
{
    struct node *tmp,*q;
    if(start == NULL)
    printf("\n list is empty");
    else
    {
        q=start;
        while(q!=NULL)
        {
            if(q->next == NULL)
            {
                q->prev->next=NULL;
                 printf("\n deleted element is %d",q->data);
                free(q);
                break;
            }
            q=q->next;
        }
    }
}
void search()
{
  struct node *ptr;
  int x,flag;
  printf("Enter the data to search:");
  scanf("%d",&x);
  if(start==NULL)
  {
     printf("\n list is empty");
  }
  else
  { 
    ptr=start;
    while(ptr!=NULL)
    {
       ptr=ptr->next;
       if(ptr->data==x)
       {
          printf("Item Found\n");
          flag=0;
       }
     }
   if(flag!=0)
    {
      printf("\nItem notfound");
   }
  }
  
}


