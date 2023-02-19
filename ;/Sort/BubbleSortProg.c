#include <stdio.h>

struct Student
{
    int RollNumber;
    char StudentName[10];
    float StudentMarks;
};

struct Student s1[10], temp;

void BubbleSort(int n)
{
    int swaps;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s1[i].RollNumber > s1[j].RollNumber)
            {
                temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
                swaps++;
            }
        }
    }
}

void main()
{
    int n;

    printf("Enter the numbers of Students: ");
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

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent roll number: %d", s1[i].RollNumber);
        printf("\t\tStudent name: %s", s1[i].StudentName);
        printf("\t\tStudent marks: %0.1f", s1[i].StudentMarks);
    }

    printf("\n\nSorting the roll numbers: \n");

    BubbleSort(n);

    for (int i = 0; i < n; i++)
    {
        printf("\nStudent roll number: %d", s1[i].RollNumber);
        printf("\t\tStudent name: %s", s1[i].StudentName);
        printf("\t\tStudent marks: %0.1f", s1[i].StudentMarks);
    }
}