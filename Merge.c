#include<stdio.h>

struct faculty
{
    int faculty_id;
    char faculty_name[50];
    char subject_code[50];
    char class_name[50];
};

void divide(int low, int high);
void merge(int low, int mid, int high);

int faculty_num;
int swap_cnt;


struct faculty f[10], temp[10];

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

    divide(0, faculty_num-1);


    //displaying sorted array
    printf("\n**********\nSorted List is as follow: ");

    for(i=0; i<faculty_num; i++)
    {
        printf("\n%d. Faculty ID: %d \t Faculty name: %s \t Subject code: %s \t Class name: %s", i+1, f[i].faculty_id, f[i].faculty_name, f[i].subject_code, f[i].class_name);
    }

    printf("\nSwap: %d", swap_cnt);
}

void divide(int low, int high)
{
    int mid;
    if (low < high)
    {
         mid = (low + high) /2;

        divide(low, mid);
        divide(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{

     int idx1 = low;
     int idx2 = mid + 1;
     int idxm = low;
     int i, j;

     while(idx1 <= mid && idx2 <= high)
     {
        if(f[idx1].faculty_id <= f[idx2].faculty_id)
        {
            temp[idxm] = f[idx1];
            idxm++; idx1++;
            swap_cnt++;
        }else
        {
            temp[idxm] = f[idx2];
            idxm++;  idx2++;
            swap_cnt++;
        }
     }

     while (idx1 <= mid)
     {
         temp[idxm] = f[idx1];
        idxm++;  idx1++;
        swap_cnt++;
     }

     while (idx2 <= high)
     {
        temp[idxm] = f[idx2];
        idxm++;  idx2++;
        swap_cnt++;
     }



    for(i=low; i<=high; i++)
    {
        f[i] = temp[i];
    }
}

