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

    //Bubble sort loop
     for(i = 0; i < len-1; i++)
     {
         for(j = 0; j < len-1 -i; j++)
         {
             if(arr[j] > arr[j+1])
             {
                 temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }

      printf("\n\nSorted array: ");
      for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
