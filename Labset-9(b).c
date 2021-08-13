#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int n,i,j;
int adj[20][20];

int max(int,int);

void warshall()
{
int i,j,k;
for (k=0;k<n;k++)
 for (i=0;i<n;i++)
  for (j=0;j<n;j++)
   adj[i][j]=max(adj[i][j],adj[i][k]&&adj[k][j]);
}

int max(int a,int b)
{
if(a>b)
return(a);
    else
return(b);
}

int main()
{
printf("Enter no. of vertices : ");
scanf("%d",&n);
printf("\nEnter adjacency matrix : \n");
for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&adj[i][j]);
warshall();
printf("\n Transitive closure: \n");
for (i=0;i<n;i++) {
for (j=0;j<n;j++)
  printf("%d\t",adj[i][j]);
printf("\n");
}
return 0;
}