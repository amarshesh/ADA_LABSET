#include <stdio.h>
#include <stdlib.h>

int n,i,j,k;
int graph[20][20];

int main()
{
  printf("Enter no. of vertices : ");
  scanf("%d",&n);
  printf("\nEnter weight matrix : \n");
for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
  floyd();
  return 0;
}
int mini(int a,int b)
{
    return (a<b?a:b);
}

void floyd()
{
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                graph[i][j]=mini(graph[i][j],graph[i][k]+graph[k][j]);
    printf("\nLength of shortest path : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}