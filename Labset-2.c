#include <stdio.h>
#include <conio.h>
#include<time.h>
void Mergeascend(int a[],int low, int mid, int high)
{
    int i, j, k, b[100000];
    i=low; j=mid+1; k=low;
    while ( i<=mid && j<=high )
     {
        if( a[i] < a[j] )
            b[k++] = a[i++] ;
        else
            b[k++] = a[j++] ;
    }
    while (i<=mid) b[k++] = a[i++] ;
    while (j<=high) b[k++] = a[j++] ;
    for(k=low; k<=high; k++)
    a[k] = b[k];
}
void Mergedescend(int a[], int low, int mid, int high)
{
   int i, j, k, b[100000];
   i=low; j=mid+1; k=low;
   while ( i<=mid && j<=high )
   {
      if( a[i] > a[j] )
           b[k++] = a[i++] ;
      else
           b[k++] = a[j++] ;
   }
    while (i<=mid) b[k++] = a[i++] ;
    while (j<=high) b[k++] = a[j++] ;
    for(k=low; k<=high; k++)
           a[k] = b[k];
}
void MergeSort(int a[], int low, int high,int flag)
{
    int mid;
    if(low >= high)
    return;
    mid = (low+high)/2 ;
    MergeSort(a, low, mid, flag);
    MergeSort(a, mid+1, high,flag);
    if(flag==0)
        Mergeascend(a, low, mid, high);
    if(flag==1)
        Mergedescend(a, low, mid, high);
}
void main()
{
    int n, k;
    clock_t clock_begin,clock_end;
    double time_taken=0.0;

    int ch;
     printf("\n Enter How many Numbers:");
     scanf("%d", &n);
     int a[n];

    while(1)
    {

     printf("\n1.random\n2.ascending\n3:descending\n4:exit\nenter your choice");
     scanf("%d",&ch);
     switch(ch)
    {
        case 1:for(k=1; k<=n; k++)
      {
         a[k]=rand()%10000000;
      }
      clock_begin=clock();
       MergeSort(a, 1, n,0);
      clock_end=clock();
      time_taken=(double)(clock_end-clock_begin)/CLOCKS_PER_SEC;

            printf("\nTime for random : %lf",time_taken);

        break;
    case 2 :clock_begin=clock();
        MergeSort(a, 1, n,0);
        clock_end=clock();
        time_taken=(double)(clock_end-clock_begin)/CLOCKS_PER_SEC;

        printf("\nThe time taken is for ascending%lf",time_taken);

        break;
    case 3 :clock_begin=clock();
        MergeSort(a, 1, n,1);
        clock_end=clock();
        time_taken=(double)(clock_end-clock_begin)/CLOCKS_PER_SEC;

        printf("\nThe time taken for descending is %lf",time_taken);
        break;
        case 4 :{exit(0);
        break;}
    }
}while(1);
}