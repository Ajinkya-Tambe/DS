#include <stdio.h>
struct Student
{
    int student_roll_no;
    char student_name[20];
    int total_marks;
};
int selectionSort(struct Student stud[], int size)
{

    int swaps = 0;

    
    for (int i = 0; i < size-1; i++)
    {
        int indexOfMin = i;
        for (int j = i+1; j < size; j++)
        {
            if(stud[indexOfMin].student_roll_no > stud[j].student_roll_no){
                indexOfMin = j;                
            }
            swaps++;
            struct Student temp = stud[i];
            stud[i] = stud[indexOfMin];
            stud[indexOfMin] = temp;
        }
    }

    return swaps;
}
void Display(struct Student *students, int n)
{
    printf("\nSorted Students Record is : \n");
    printf("\n\nName\tRoll Number\tMarks");
    for (int j = 0; j < n; j++)
    {
        printf("\n%s\t\t%d\t%d", students[j].student_name, students[j].student_roll_no, students[j].total_marks);

        printf("\n");
    }
}
int main()
{

    int size = 0;

    printf("Enter the number of students you want to sort: ");
    scanf("%d", &size);

    struct Student students[size];

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the details of %d Student ", i + 1);
        printf("\nName: ");
        getchar();
        gets(students[i].student_name);
        printf("Roll Number: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].total_marks);
    }

    int numOfSwaps = selectionSort(students, size);
    printf("\nAfter swap:\n");
    Display(students, size);
    printf("Number of swaps: %d", numOfSwaps);
    return 0;
}
