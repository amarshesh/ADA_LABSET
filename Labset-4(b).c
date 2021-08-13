#include <math.h>
#include <stdio.h>
int main()
{
    int n,i;
    printf("enter the size of the array \n ");
    scanf("%d",&n);
    int array[n];
    printf("\n \n enter the elements to the array to sort \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }
    insertionSort(array, n);
    display(array, n);

    return 0;
}
void insertionSort(int array[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

void display(int array[], int n)
{
    int i;
    printf("\n sorted array \n ");
    for (i = 0; i < n; i++)
        printf(" %d ", array[i]);
    printf("\n");
}