#include<stdlib.h>
#include<stdio.h>
#include<time.h>


void heapify(int arr[],int n,int i)
{
  int largest =i,temp;
  int l=2*i+1;
  int r=2*i+2;
  if(l<n&&arr[l]>arr[largest])
      largest=l;
  if(r<n&&arr[r]>arr[largest])
      largest=r;
  if(largest!=i)
   {

      temp=arr[i];
      arr[i]=arr[largest];
      arr[largest]=temp;
      heapify(arr,n,largest);


   }
}
void heapsort(int arr[],int n)
  {
   for(int i=n/2-1;i>=0;i--)
       heapify(arr,n,i);
   for(int i=n-1;i>=0;i--)
   {
      int temp=arr[0];
          arr[0]=arr[i];
          arr[i]=temp;
          heapify(arr,i,0);
   }


}
void printarray(int arr[],int n)
{
    for(int i=0;i<n;++i)
    {
        printf("%d",arr[i]);
        printf("\t");
    }
    printf("\n");
}
int main()
{
    int i,n,choice;
    clock_t clock_begin,clock_end;
    double timeTaken = 0.0;
    while(1)
    {
    printf("\n\n1.generate random numbers \n2.exit\n enter the choice :\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:{
            printf("\n enter how many random numbers you want to generate.");
            scanf("%d",&n);
            int arr[n];
            srand(time(NULL));
            for(i=0;i<n;i++)
            {
              arr[i] = rand()%1000000;
            }
           /* printf("array elements are: \n");
          for(int i=0;i<n;i++)
          printf("%d\t",arr[i]);
          printf("\t");
          printf("\n");*/


          n=sizeof(arr)/sizeof(arr[0]);
          clock_begin = clock();
          heapsort(arr,n);
          clock_end = clock();
          timeTaken = (double)(clock_end-clock_begin)/CLOCKS_PER_SEC;
          printf("time spent %lf",timeTaken);
          /*printf("\n\nsorted array is: \n");
          printarray(arr,n);*/
          break;
    }
    case 2:exit(0);
    default: printf("\n invalid input");
  }
}
}