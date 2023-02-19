#include<stdio.h>

struct faculty
{
    int faculty_id;
    char faculty_name[50];
    char subject_code[50];
    char class_name[50];
};

int faculty_num;
int swap_cnt = 0;

struct faculty f[10];

void max_heap(struct faculty f[], int n);
void heapify(struct faculty f[], int n, int i);

void main()
{
    int i, low, high, mid;
    
    printf("\n\nEnter total number of faculties: ");
    scanf("%d", &faculty_num);

    //taking the input from user
    for(i=0; i<faculty_num; i++)
    {

        printf("\nEnter ID of faculty number- %d: ", i+1);
        scanf("%d", &f[i].faculty_id);
        printf("Enter name of faculty number- %d: ", i+1);
        scanf("%s", &f[i].faculty_name);
        printf("Enter subject code faculty is associated with: ");
        scanf("%s", &f[i].subject_code);
        printf("Enter class name faculty is associated with: ");
        scanf("%s", &f[i].class_name);
        printf("\n");

    }

    //displaying the input:
    printf("\n**********\nEntered list is as follow: ");
    for(i=0; i<faculty_num; i++)
    {
        printf("\n%d. Faculty ID: %d \t Faculty name: %s \t Subject code: %s \t Class name: %s", i+1, f[i].faculty_id,f[i].faculty_name, f[i].subject_code, f[i].class_name);
    }

    max_heap(f, faculty_num);

    //displaying sorted array
    printf("\n**********\nSorted List is as follow: ");

    for(i=0; i<faculty_num; i++)
    {
        printf("\n%d. Faculty ID: %d \t Faculty name: %s \t Subject code: %s \t Class name: %s", i+1, f[i].faculty_id, f[i].faculty_name, f[i].subject_code, f[i].class_name);
    }

    printf("\n\nSwap Required: %d", swap_cnt);
}

void swap(struct faculty *ptr1, struct faculty *ptr2)
{
    struct faculty temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    swap_cnt++;
}


void max_heap(struct faculty f[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(f, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap(&f[0], &f[i]);
        heapify(f, i, 0);
    }
}


void heapify(struct faculty f[], int n, int i)
{
    int max = i;
    int l_child = 2 * i + 1;
    int r_child = 2 * i + 2;

    if (l_child < n && f[l_child].faculty_id > f[max].faculty_id)
        max = l_child;

    if (r_child < n && f[r_child].faculty_id > f[max].faculty_id)
        max = r_child;

    if (max != i)
    {
        swap(&f[i], &f[max]);
        heapify(f, n, max);
    }
}

