#include <stdio.h>

struct Student
{
    int RollNumber;
    char StudentName[10];
    float StudentMarks;
};

struct Student s1[10], temp;

int partitionFun(int lower, int higher)
{
    int pivot = s1[lower].RollNumber;
    int i = lower, j = higher;
    int swaps;


    while (i < j)
    {
        do
        {
            i++;
        } while (s1[i].RollNumber < pivot);

        do
        {
            j--;
        } while (s1[j].RollNumber > pivot);

        if (i < j)
        {
            temp = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
            swaps++;
        }
    }

    temp = s1[lower];
    s1[lower] = s1[j];
    s1[j] = temp;
    
    return j;
}

void QuickSort(int lower, int higher)
{
    if (lower < higher)
    {
        int j = partitionFun(lower, higher);
        QuickSort(lower, j);
        QuickSort(j + 1, higher);
    }
}

void main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter roll number of student %d: ", i + 1);
        scanf("%d", &s1[i].RollNumber);

        printf("Enter name of student %d: ", i + 1);
        scanf("%s", &s1[i].StudentName);

        printf("Enter marks obtained by student %d: ", i + 1);
        scanf("%f", &s1[i].StudentMarks);
    }

    int lower = 0, higher = n;

    for (int i = 0; i < n; i++)
    {
        printf("\n\nStudent roll number: %d", s1[i].RollNumber);
        printf("\nStudent name: %s", s1[i].StudentName);
        printf("\nStudent marks: %0.1f", s1[i].StudentMarks);
    }

    QuickSort(lower, higher);

    printf("\n\nSorting the roll numbers: ");
    // printf("\nNumber of swaps taken: %d", swaps);

    for (int i = 0; i < n; i++)
    {
        printf("\n**********************************************");
        printf("\nStudent roll number: %d", s1[i].RollNumber);
        printf("\nStudent name: %s", s1[i].StudentName);
        printf("\nStudent marks: %0.1f", s1[i].StudentMarks);
    }
}