#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double time_spent=0.0;
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
int partition (int arr[], int l, int r)
{
 int piv = arr[r];
 int i = (l - 1);
 for (int j = l; j <= r - 1; j++)
 {
 if (arr[j] < piv)
 {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[r]);
 return (i + 1);
}
void quickSort(int arr[], int l, int r)
{
 if (l < r)
 {
 int x = partition(arr, l, r);
 quickSort(arr, l, x - 1);
 quickSort(arr, x + 1, r);
 }
}
void descending(int n)
{
 int ar[n],i,c=0;
 for(i=n-1;i>=0;i--)
 {
 ar[c]=i;
 c++;
 }
 clock_t begin = clock();
 quickSort(ar, 0, n-1);
 clock_t end = clock();
 time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
}
void ascending(int n)
{
 int ar[n],i;
 for(i=0;i<n;i++)
 {
 ar[i]=i;
 }
clock_t begin = clock();
 quickSort(ar, 0, n-1);
 clock_t end = clock();
 time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
}
void random(int n)
{
 int i,num=n,ar[n];
 i=0;
 srand(time(NULL));
 while(n-->0)
 {
 ar[i]=rand()%10000000;
 i++;
 }

}
int main()
{
 int ch,n;

 while(1)
 {
 printf("\n ");
 printf("\n1. random \n2. Ascending Order\n3. Descending Order \n4.Exit\nEnter choice\n");
 scanf("%d",&ch);
 printf("\n");
 printf("enter the size\n");
 scanf("%d",&n);
 switch(ch)
 {
 case 1 :random(n);
        ascending(n);
 printf("time spent to sort in Random Order= %lf\n",time_spent);
 break;
 case 2 :
 ascending(n);
printf("time spent to sort in Ascending Order= %lf\n",time_spent);
 break;
 case 3:descending(n);
 printf("time spent to sort in Descending Order= %lf\n",time_spent);
 break;
 case 4 :
 exit(0);
 break;
 default :
 printf("Wrong Choice \n");
 }
 }
 return 0;
}