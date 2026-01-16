#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[40];
    int start_time;
    int end_time;
};
int count;
int count2;
struct node process[100];
struct node schedule[100];

void set_process(char name[],int start, int end)
{
    strcpy(process[count].name,name);
    process[count].start_time = start;
    process[count].end_time = end;
    count++;
}
void show_processes()
{
    for (int i =0; i < count ; i ++)
    {
        printf("process name: %s, starting time: %d, ending time: %d\n",process[i].name,process[i].start_time,process[i].end_time);
    }
}
void print_schedule ()
{
    for (int i =0; i < count2 ; i ++)
    {
        printf("process name: %s, starting time: %d, ending time: %d\n",schedule[i].name,schedule[i].start_time,schedule[i].end_time);
    }
}
void sort()
{
    struct node temp;
    int count2;
    for (int i =0; i< count-1; i++)
    {
        for(int j=0; j<count-1; j ++)
        {
            if (process[j].end_time>process[j+1].end_time)
            {
                temp =  process[j];
                process[j] =process[j+1];
                process[j+1] = temp;
            }
        }
    }
}
void greedy()
{
    schedule[count2] = process[0];
    int etime = schedule[count2].end_time;
    count2++;
    for (int i =1;i<count; i++)
    {
        if(process[i].start_time >= etime)
        {
            schedule[count2] = process[i];
            etime = schedule[count2].end_time;
            count2++;
        }
    }
}
int main ()
{
    set_process("a",1,3);
    set_process("b",2,5);
    set_process("c",3,9);
    set_process("d",6,8);

    show_processes();
    sort();
    printf("after sorting \n");
    show_processes();
    printf("process can be scheduled\n");
    greedy();
    print_schedule();
    return 0;
}
