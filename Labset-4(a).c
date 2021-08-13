#include <stdio.h>
#include <stdlib.h>

int temp[10];
int k=0;
int n;

int main()
{
    int i,j,indeg[10],a[10][10];
    printf("Enter no. of vertices : ");
    scanf("%d",&n);
    printf("\n enter adjacency matrix \n ");
    for(i=1;i<=n;i++)
        indeg[i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                indeg[j]++;
        }
    }
    topo(indeg,a);
    if(k!=n)
        printf("Topological ordering not possible\n");
    else
    {
        printf("Topological order :\n");
        for(i=1;i<=n;i++)
            printf("v%d\t",temp[i]);
    }
}

void topo(int indeg[10],int a[10][10])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            indeg[i]=1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1&&indeg[j]!=-1)
                    indeg[j]--;
            }
            i=0;
        }
    }
}