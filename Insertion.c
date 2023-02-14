#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[] = {9,10,2,4,0,1, -5};
    int temp = 0;
    int i,j;
    int len = sizeof(arr) / sizeof(arr[0]);
    //printf("%d", len);

    printf("Given array: ");
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);

    //Insertion Sort
    for(i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

      printf("\n\nSorted array: ");
      for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
