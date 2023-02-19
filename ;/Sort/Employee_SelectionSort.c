#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    char emp_name[50];
    int emp_no, emp_salary;
};

struct Employee emp[100];

int selectionSort(int size)
{
    int cnt = 0;

    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if(emp[min].emp_no > emp[j].emp_no){
                min = j;
            }
        }

        if(min != i){
            cnt++;
        }

        struct Employee temp = emp[i];
        emp[i] = emp[min];
        emp[min] = temp;
    }

    return cnt;
}

void display(int size)
{
    printf("\n");
    printf("Employee Name \tEmployee Number \tSalary\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s\t\t%d\t\t%d\n", emp[i].emp_name, emp[i].emp_no, emp[i].emp_salary);
    }
}

int main()
{
    int n;
    printf("Enter number of employee records to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter details of Employee %d as Employee Name, Number and Salary: ", (i + 1));
        scanf("%s %d %d", emp[i].emp_name, &emp[i].emp_no, &emp[i].emp_salary);
    }

    int cnt = selectionSort(n);
    printf("\nArray after Sorting: ");
    display(n);
    printf("\nNumber of swaps: %d", cnt);

    return 0;
}
