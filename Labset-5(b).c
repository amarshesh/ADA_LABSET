#include <stdio.h>
#include <stdlib.h>
# define size 20
int q[size],visited[20],rear=-1,front=0;
int n,s,adj[20][20],flag=0;
void insertq(int v)
{
    q[++rear]=v;
}
int deleteq()
{
    return(q[front++]);
}
int qempty()
{
    if(rear<front)
        return 1;
    else
        return 0;
}
void bfs(int v)
{
    int w;
    visited[v]=1;
    insertq(v);

while(!qempty())
{
   // v=deleteq();
    for(w=1;w<=n;w++)
    {
        if((adj[v][w]==1)&&(visited[w]==0))
        {
            visited[w]=1;
            flag=1;
            printf("vertex %d \t ",w);
            insertq(w);
        }
    }
    deleteq();
}
}
void main()
{
    int v,w;
    printf("\n enter the number of vertices \n:");
    scanf("%d",&n);
    printf("\n enter adjacency matrix ");
    for(v=1;v<=n;v++)
    {
        for(w=1;w<=n;w++)
            scanf("%d",&adj[v][w]);
    }
    printf("\n enter the start vertex");
    scanf("%d",&s);
    printf("reachability of vertex %d\n ",s);
    for(v=1;v<=n;v++)
         visited[v]=0;

     bfs(s);
     if(flag==0)
    {
        printf("no path found \n");
    }
}