#include<stdio.h>
#include<math.h>
int x[100],count=0;
  int place(int k,int i)
  {
   for(int j=1;j<k;j++)
  {
  if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
  return 0; 
  }
  return 1;
  }

 void nqueens(int k,int n)
 {
  for(int i=1;i<=n;i++)
 {
 if(place(k,i))
 {
  x[k]=i;
  if(k==n)
  {
   count++;
   printf("\n");
   for(int j=1;j<=n;j++)
   {
     for(int p=1;p<=n;p++)
     {
     if(x[j]==p)
       printf("q\t");
     else
       printf("#\t");
     }
    printf("\n");
   }
  }
  else
  nqueens(k+1,n);}}}
 int main()
{
int n;
printf("enter number of queens: ");
scanf("%d",&n);
nqueens(1,n);
if(count==0)
  printf(" No solution\n");
else
  printf("\n Number of solutions is %d",count);
return 0;
}

