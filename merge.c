#include<stdio.h>
int main()
{
 	int n1, n2, n3, i, j;
 	int a[50],b[50],c[50];     
 	printf("\n Enter the size of first array: ");
 	scanf("%d", &n1);  
 	printf("\nEnter the elements for first Array:");
 	for(i = 0; i < n1; i++)
  	{
      	scanf("%d", &a[i]);
  	}
  	printf("\n Enter the size of second array:");
 	scanf("%d", &n2);  
 	printf("\nEnter the elements for second array:");
 	for(i = 0; i < n2; i++)
  	{
      	scanf("%d", &b[i]);
  	}
	n3 = n1 + n2;     
  	for(i = 0; i < n1; i++)
  	{
      	c[i] = a[i];
  	}
 	for(i = 0, j = n1; (j < n3)&& (i < n2); i++, j++)
  	{
  		c[j] = b[i];
  	}
 	printf("\nThe Elements After Merging \n"); 
 	for(i = 0; i < n3; i++)
  	{
    	printf(" %d \t ",c[i]);
  	}
  	return 0;
}


