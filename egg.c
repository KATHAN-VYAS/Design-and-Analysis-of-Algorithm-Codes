#include<stdlib.h>
#include <stdio.h>

struct node {
    long long data;
    struct node *next;
};
void traverse(struct node *start)
{
    struct node *current = start;
    while (current != NULL)
    {
        printf("%lld->",current->data);
        current = current->next;
    }
}
void traverseReverse(struct node *start)
{
    if (start == NULL)
{
    return;
}
traverseReverse(start-> next);
printf("%lld",start->data);
}
void addfirst(struct node **first, long long newdata)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;

    newnode->next = *first;

    *first = newnode;
}
void addlast(struct node **start, long long newdata)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;

    if (*start ==NULL)
    {
        *start = newnode;
    }
    else {
        struct node *current = *start;
        while (current-> next != NULL)
        {
            current = current-> next;
        }
        current->next = newnode;
    }
}
struct node *addnumbers (long long num)
{
    struct node *first=NULL;
    
    while (num>0)
    {
        long long a= num%10;
        addfirst(&first, a);
        num = num/10;
    }
    return first;
}

struct node *addition(struct node *num1, struct node *num2)
{

    struct node *start1 = NULL;
    

    struct node *current1 = num1;
    struct node *current2 = num2;

    while (current1!=NULL && current2 != NULL)
    {   
        if (current1->data+current2->data >9)
        {
            addlast(&start1, (current1->data+current2->data+carry)%10);
            long long carry = (current1->data+current2->data)/10
        }
        else{
            addlast(&start1, current1->data+current2->data+carry);
            long long carry =0; 
        }
        

        current1 = current1->next;
        current2 = current2->next;
        if 
    }
    return start1;
    
}
int main ()
{
    long long num1 =135;
    long long num2 = 12;

    struct node *list1 = addnumbers(num1);
    struct node *list2 = addnumbers(num2);
    int n = num1;
    int m = num2;

    int length1 = 0;
    while (n != 0) {
        length1++;
        n /= 10;
    }
    int length2 = 0;
    while (m != 0) {
        length2++;
        m /= 10;
    }

    if (length1>length2){
        for (int i=0; i<length1-length2; i++)
        {
            addfirst(&list2,0);
        }
    }
    if (length1<length2){
        for (int i=0; i<length2-length1; i++)
        {
            addfirst(&list1,0);
        }
    }

    printf("first number: ");
    traverse(list1);
    printf("\n second number: ");
    traverse(list2);
    struct node *ans1 = addition(list1, list2);
    printf("\n addition of numbers is: ");
    traverse(ans1);

    return 0;
}
