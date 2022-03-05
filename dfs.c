#include<stdio.h>
void dfs(int);
int a[10][10],visited[10],n;
void main()
{
  int i,j;
  printf("Enter the number of vertices:");
  scanf("%d",&n);
  printf("Enter the adjacency matrix:");
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
         scanf("%d",&a[i][j]);
     }
  }
  for(i=0;i<n;i++)
  {
     visited[i]=0;
  }
  dfs(0);
}
void dfs(int i)
{
  int j;
  printf("%d",i);
  visited[i]=1;
  for(j=0;j<n;j++)
  {
     if(a[i][j]==1 && visited[j]==0)
     {
       dfs(j);
     }
  }
}
  
