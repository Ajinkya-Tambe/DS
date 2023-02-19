#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int swap_count = 0;

typedef struct Faculty
{
    int faculty_ID;
    char faculty_name[MAX];
    int subject_code;
    char class_name[MAX];
} Faculty;

void printFacultDetails(Faculty *f, int size)
{
    printf("\n-----------------------------------------------------------------");
    printf("\n                        Faculty Details: ");
    printf("\n-----------------------------------------------------------------");
    printf("\nFaculty ID | Faculty Name | Subject Code | Class Name\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d          %s          %d          %s \n",
               f[i].faculty_ID, f[i].faculty_name, f[i].subject_code, f[i].class_name);
    }
    printf("\n----------------------------------------------------------------");
}

void getFacultyDetails(Faculty *f, int size)
{
    printf("\n-----------------------------------------------------------------");
    printf("\n                    Enter Faculty Details: ");
    printf("\n-----------------------------------------------------------------");
    printf("\nEnter Faculty ID, Faculty Name, Subject Code, Class Name\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d %s %d %s", &f[i].faculty_ID, &f[i].faculty_name, &f[i].subject_code, &f[i].class_name);
    }
    printf("\n-----------------------------------------------------------------");
}
void swap(Faculty *a, Faculty *b)
{
    Faculty temp = *a;
    *a = *b;
    *b = temp;
    swap_count++;
}

void selectionSort(Faculty *f, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(f[j].faculty_ID < f[indexOfMin].faculty_ID){
                indexOfMin = j;
            }
        }
        swap(&f[indexOfMin], &f[i]);
    }
}

int main()
{
    printf("\n\n Selection Sort \n\n");
    printf("Enter the number of Faculty : ");
    int size;
    scanf("%d", &size);

    Faculty *f;
    f = malloc(sizeof(Faculty) * size);

    getFacultyDetails(f, size);
    selectionSort(f, size);

    printf("\n\n \t\t\t After Sorting \n\n");
    printFacultDetails(f, size);
    printf("\n\n Total Numbers Swaps Performed : %d", swap_count);
    free(f);
    return 0;
}