#include <iostream>

using namespace std;
void knapsack(int n,int m,int w[],int p[])
{
    int mat[n+1][m+1],i,j;
    for(i=0;i<=n;i++)
    {
        mat[i][0]=0;
    }
    for(j=0;j<=m;j++)
    {
        mat[0][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(w[i-1]<=j)
            {
                if(mat[i-1][j]>(p[i-1]+mat[i-1][j-w[i-1]]))
                {
                    mat[i][j]=mat[i-1][j];
                }
                else
                {
                    mat[i][j]=p[i-1]+mat[i-1][j-w[i-1]];
                }
            }
            else
            {
                mat[i][j]=mat[i-1][j];
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int temp = mat[n][m];
    int res = temp;
    cout<<"The total profit is "<<res<<endl;
    i=n;
    j=m;
    cout<<"The items in the knapsack are :"<<endl;
    while(temp!=0){
    while(mat[i][j]==mat[i-1][j])
    {
        i--;
    }
    cout<<i<<" ";
   // cout<<w[i-1]<<" ";
    temp-=p[i-1];
    i=i-1;
    while(mat[i][j]!=temp)
    {
        j--;
    }
    }

}