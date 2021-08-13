#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int max=0,min=0;


int BubbleSort(FILE *fp,int store[],int n)
{
 double time = 0.0;
 int i,j,temp;
 clock_t begin = clock();
 for(i = 0; i < n-1; i++)
 {
  for(j = i + 1; j < n; j++)
  {
   if(store[i]>store[j])
   {
    temp = store[i];
    store[i] = store[j];
    store[j] = temp;
   }
  }
 }
 for(int i = 0; i<n; i++)
 {
  printf(" ->%d ",store[i]);
  fprintf(fp, "%d ", store[i]);
 }
 clock_t end = clock();
 time = (double)(end-begin)/CLOCKS_PER_SEC;
 printf("time spent %lf",time);
}



int linearSearch(int key,int a[],int n)
{

 if(n>=0)
 {
  if(a[n-1] == key)
  {
   return (n-1);
  }
  else
  {
   return linearSearch(key,a,n-1);
  }
  n--;
 }
}


int binarySearch(int a[], int low, int high, int key)
{
 int mid;
 if(low>high)
 {
  return -1;
 }
 mid = (low + high)/2;
 if(key == a[mid])
 {
  return(mid + 1);
 }
 if(key < a[mid])
 {
  return(binarySearch(a,low,mid-1,key));
 }
 return binarySearch(a,mid+1,high,key);
}

int nRecursion(int a[], int n)
{
 int max=0;
 for(int i=0;i<=n;i++)
 {
  if(a[i]>max)
   max=a[i];
 }
 return max;
}

int minele(int a[], int n)
{
 int min=a[0];
 for(int i=0;i<=n;i++)
 {
  if(a[i]<min)
   min=a[i];
 }
 return min;
}

int main(void)
{
 int result1,result2,choice,result,x,i,n,key,a;
 FILE *fp;
 fp = fopen("DATA.txt", "a");
 printf("\n enter the number of random number to be generated.");
 scanf("%d",&n);
 int store[n];
 for(int i = 0; i < n; i++)
 {
  store[i] = rand();
 }
 for(int i = 0; i<n; i++)
 {
  printf(" ->%d ",store[i]);
  fprintf(fp, "%d ", store[i]);
 }
 fclose(fp);
 while(1)
 {
  printf("\n 1.linearSearch \n 2.binarySearch \n 3.MAX\n4.MIN\n 5. bubble sort\n6 exit\n enter choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:fp = fopen("DATA.txt","a");
   printf("\n enter the key to search");
        scanf("%d",&key);
         i =0;
        while((fscanf(fp,"%d",store[i]))!=EOF)
        {
         i++;
        }
        printf("ele is found at %d",linearSearch(key,store,n) + 1);
        fclose(fp);
        break;
    case 2: fp = fopen("DATA.txt","w");
        printf("\n enter the key to search");
        scanf("%d",&key);
        i=0;   
        break;
    case 3: printf("max ele %d\n", nRecursion(store, n-1));
         break;
    case 4: printf("min ele %d\n", minele(store, n-1));
         break;
    case 5: fp = fopen("DATA.txt","w");
        BubbleSort(fp,store,n);
        fclose(fp);
        break;
    case 6: exit(0);
    default: printf("\n not valid input");
   }
  }
  return 0;
}