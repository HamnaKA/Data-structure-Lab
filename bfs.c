#include<stdio.h>
void bfs(int); 
int a[10][10],visited[10],q[20],n,i,j,f=-1,r=-1;
void main()
{
  int v;
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
  printf("Enter the starting vertex:");
  scanf("%d",&v);
  f=r=0;
  q[f]=v;
  printf("\n BFS traversal is:\n");
  visited[v]=1;
  printf("%d",v);
  bfs(v);
}
void bfs(int v)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(a[v][i]==1 && visited[i]==0)
    {
      r=r+1;
      q[r]=i; //insert item into queue
      visited[i]=1; //mark vertex visited
      printf("%d",i);
     
   }
  }
   f=f+1;  //remove vertex at front of queue
   if(f<=r) //as long as element in queue
     bfs(q[f]); //perform bfs in front of queue
}
   

