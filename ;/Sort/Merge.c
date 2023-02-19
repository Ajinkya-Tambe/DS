#include<stdio.h>

struct faculty
{
    int f_id;
    char f_name[50];
    char subject_code[50];
    char class_emp[50];
};

int faculty_num;
struct faculty f[10], temp[10];


void mergeSort(int low, int mid, int high)
{

     int i1 = low;
     int i2 = mid + 1;
     int idxm = low;
     int swap_cnt = 0;
     int i, j;

     while(i1 <= mid && i2 <= high)
     {
        if(f[i1].f_id <= f[i2].f_id)
        {
            temp[idxm] = f[i1];
            idxm++; i1++;
            swap_cnt++;
        }else
        {
            temp[idxm] = f[i2];
            idxm++;  i2++;
            swap_cnt++;
        }
     }

     while (i1 <= mid)
     {
         temp[idxm] = f[i1];
            idxm++;  i1++;
            swap_cnt++;
     }

     while (i2 <= high)
     {
        temp[idxm] = f[i2];
            idxm++;  i2++;
            swap_cnt++;
     }

    for(i=low; i<=high; i++)
    {
        f[i] = temp[i];
    }
}


void divide(int low, int high)
{
    if( low >= high)
        return;

    int mid = (low + high) /2;

    divide(low, mid);
    divide(mid + 1, high);
    mergeSort(low, mid, high);
}



void main()
{
    int i, low, high, mid;
    
    printf("\n\nEnter total number of faculties: ");
    scanf("%d", &faculty_num);

    //taking the input from user
    for(i=0; i<faculty_num; i++)
    {

        printf("\nEnter ID of faculty number- %d: ", i+1);
        scanf("%d", &f[i].f_id);
        printf("Enter name of faculty number- %d: ", i+1);
        scanf("%s", &f[i].f_name);
        printf("Enter subject code faculty is associated with: ");
        scanf("%s", &f[i].subject_code);
        printf("Enter class name faculty is associated with: ");
        scanf("%s", &f[i].class_emp);
        printf("\n");

    }

    //displaying the input:
    printf("Entered list is as follow: ");
    for(i=0; i<faculty_num; i++)
    {
        printf("\n%d. Faculty ID: %d\nFaculty name: %s\nSubject code: %s\nClass name: %s\n\n", i+1, f[i].f_id,f[i].f_name, f[i].subject_code, f[i].class_emp);
    }

    divide(0, faculty_num-1);    


    //displaying sorted array
    printf("Sorted List is as follow: ");

    for(i=0; i<faculty_num; i++)
    {
        printf("\n%d. Faculty ID: %d\nFaculty name: %s\nSubject code: %s\nClass name: %s\n\n", i+1, f[i].f_id, f[i].f_name, f[i].subject_code, f[i].class_emp);
    }
}


