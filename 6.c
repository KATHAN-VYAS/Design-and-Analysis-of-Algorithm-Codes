#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node {
    char city[40];
    int x_cordinate;
    int y_cordinate;
    struct node *next;
};

void traverse(struct node *start)
{
    while (start != NULL)
    {
        printf(" |%s", start->city);
        printf("|%d", start->x_cordinate);
        printf("|%d| -->", start->y_cordinate);
        start = start->next;
    }
}
// *** ((note : pointer of char is string)) ***
void addfirst(struct node **first, char *city, int x_cordinate, int y_cordinate)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.");
        return;
    }
    //to add asomthing to char-node it is requires to use (strcpy)
    strcpy(newNode->city, city);
    newNode->x_cordinate = x_cordinate;
    newNode->y_cordinate = y_cordinate;
    // Set the next pointer of the new node to the current first node
    newNode->next = *first;

    // Set the new node as the first node
    *first = newNode;
}

void addlast(struct node *first, char *city, int x_cordinate, int y_cordinate)
{   
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (first == NULL)
    {
        strcpy(newNode->city,city);
        newNode->x_cordinate = x_cordinate;
        newNode->y_cordinate = y_cordinate;
        first = newNode;
        newNode->next = NULL;
    }  
}

// Delete by data
void delete(struct node **first, char delcity[40])
{
    struct node *temp,*prev;

    // If the first node is to be deleted
    if (*first != NULL && strcmp((*first)->city, delcity) == 0)
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
        return;
    }

    // Find the node to be deleted
    prev = *first;
    while (prev->next !=NULL)
    {
        if (strcmp(prev->next->city, name)==0)
        {
            temp = prev->next;
            prev->next= temp->next;
            free(temp);
            return;
        }
        prev = prev->next;
    }
}
struct node *search_record_by_name(struct node *first, char name[40])
{
    while (first != NULL)
    {
        if (strcmp(first->city, name) == 0)
            return first;
        first = first->next;
    }
    return NULL;
}
void print_records_within_distance(struct node *first, int x, int y, float distance)
{
    while (first != NULL)
    {
        float dist = sqrt(pow(first->x_cordinate - x, 2) + pow(first->y_cordinate - y, 2));
        if (dist <= distance)
        {
            printf(" |%s", first->city);
            printf("|%d", first->x_cordinate);
            printf("|%d| -->", first->y_cordinate);
        }
        first = first->next;
    }
}

int main()
{
    struct node *first = NULL;

    // Allocate memory for the first node
    first = (struct node *)malloc(sizeof(struct node));

    // Initialize first node
    strcpy(first->city, "surat");
    first->x_cordinate = 1;
    first->y_cordinate = 1;
    first->next = NULL;

    // Add a new node
    addfirst(&first, "botad", 2, 2);
    addfirst(&first, "ahmedabad", 32, 31);
    // delete(&first, "botad");
    // Traverse and print nodes
    traverse(first);
    printf("\nprinting recode is radius 10 from 0,0 \n");
    print_records_within_distance(first, 0,0,10);
    // Free allocated memory
    struct node *current = first;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}