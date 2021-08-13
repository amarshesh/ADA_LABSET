#include<stdio.h>
#include<stdlib.h>

int s[10],d[10],cost[10][10],n,v;

int choose()
{
    int m=999,w;
    for(int j=1;j<=n;j++)
    {
        if((d[j]<m) && !s[j])
        {
            m = d[j];
            w = j;
        }
    }
    return w;
}

void djistra()
{
    int i,j,u;
    printf("\nEnter the source vertex:");
    scanf("%d",&v);
    for(int i=1; i<=n; i++)
    {
            s[i]=0;
            d[i]=cost[v][i];
    }
    s[v]=1;
    d[v]=0;
    i=2;
    while(i<n)
    {
        u=choose();
        s[u]=1;
        i++;
        for(int w=1;w<=n;w++)
            if((d[u]+cost[u][w] <d[w]) && !s[w])
                d[w] = d[u]+ cost[u][w];
    }
}

int main()
{
    printf("Enter no. of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
        scanf("%d",&cost[i][j]);
    }
    djistra();
    for(int i=1;i<=n;i++)
        if(i!=v)
            printf("(%d,%d) => %d\n",v,i,d[i]);
    return 0;
}