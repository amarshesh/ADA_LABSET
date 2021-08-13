#include <stdio.h>
int a[10][10];
int mini(int a, int b)
{
    return(a<b?a:b);

}
int binomial(int n, int k)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=mini(i,k);j++)
        {
            if(j==0 || j==i)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1] + a[i-1][j];
        }
    }
    return a[n][k];
}

int main()
{
    int n,k;
    printf("enter the integer n:");
    scanf("%d",&n);
    printf("enter the integer r:");
    scanf("%d",&k);
    printf("binomial coefficient of %dc%d is ",n,k);
    printf("%d \n \n ", binomial(n,k));


    for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                printf("%d",a[i][j]);
                printf("\t");

            }
            printf("\n");

        }
        return 0;
    }