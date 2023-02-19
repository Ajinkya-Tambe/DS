#include <stdio.h>

struct Student
{
    int RollNumber;
    char StudentName[10];
    float StudentMarks;
};

struct Student s1[10], temp;

void insertionSort(int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = s1[i].RollNumber;
        j = i-1;
        // Loop for each pass
        while(j>=0 && s1[j].RollNumber > key){
            s1[j+1] = s1[j];
            j--;
        }
        s1[j+1].RollNumber = key;
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

    insertionSort(n);

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



