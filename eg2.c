#include<stdio.h>
#include<stdlib.h>

struct classroom{
    int end;
    int count;
};
struct schedule{
    int start;
    int end;
};
int m;
struct schedule schedules[100];
struct classroom *classrooms;
int n =5;

void sort ()
{
    for (int i =0; i<n;i++ )
    {
        for (int j =i+1; j< n; j++)
        {
            if (schedules[i].start >=schedules[j].end )
            {
                struct schedule temp = schedules[i];
                schedules[i] = schedules[j];
                schedules[j] = temp;
            }
        }
    }
}
int set()
{   classrooms = (struct classroom*)malloc(m * sizeof(struct classroom));
    int m =1;
    sort();
    for (int i =0; i<n; i++)
    {
        for (int j =0; j< m ; j++)
        {
            if(schedules[i].start >= classrooms[j].end)
            {
                classrooms[j].end = schedules[i].end;
                classrooms[j].count ++;
                break;
            }
            else {
    classrooms = (struct classroom*)realloc(classrooms, m * sizeof(struct classroom));
    classrooms[m].end = schedules[i].end;
    classrooms[m].count++;
    m++;
}

        }
        
    }
    return m;
}

int main ()
{

    schedules[0].start = 0;
schedules[0].end = 3;
schedules[1].start = 1;
schedules[1].end = 4;
schedules[2].start = 2;
schedules[2].end = 5;
schedules[3].start = 3;
schedules[3].end = 6;
schedules[4].start = 5;
schedules[4].end = 7;


    set();
    printf("Classrooms:\n%d",m);
   
    return 0;
}
