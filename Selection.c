#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[] = {9,10,2,4,0,1, -5};
    int temp = 0;
    int i, j, min;
    int len = sizeof(arr) / sizeof(arr[0]);
    //printf("%d", len);

    printf("Given array: ");
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);

    //Selection sort
     for(i = 0; i < len -1; i++)
     {
         min =i;
         for(j = i+1; j < len; j++)
         {
             if(arr[j] < arr[min])
                min = j;
         }
         temp = arr[min];
         arr[min] = arr[i];
         arr[i] = temp;
     }

      printf("\n\nSorted array: ");
      for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

