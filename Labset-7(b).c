#include<stdio.h>

void counting(int a[],int n,int max)
{
   int count[50]={0},i,j;
   for(i=0;i<n;++i)
          count[a[i]]=count[a[i]]+1;
   printf("sorted elements are");
   for(i=0;i<=max;++i)
   for(j=1;j<=count[i];++j)
       printf("%d ",i);
}
int main()
  {
int a[50],n,i,max=0;
printf("enter the number of elements: ");
scanf("%d",&n);
printf("\n enter elements");
for(i=0;i<n;++i)
{
scanf("%d",&a[i]);
if(a[i]>max)
max=a[i];
}
counting(a,n, max);
return 0;
}