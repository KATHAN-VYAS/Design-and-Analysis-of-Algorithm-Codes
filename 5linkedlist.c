//linked list and adding elements in linked list

#include <stdlib.h>
#include <stdio.h>

struct node {
    long long data;   // Change data type to long long
    struct node *next;
};

void traverseReverse(struct node *start)
{
    if (start == NULL)
        return;
    // Recursively traverse to the end of the list (using stack via recursion)
    traverseReverse(start->next);
    // Print the current node data
    printf(" %lld -> ", start->data);   // Change %d to %lld
}

void addfirst(struct node **first, long long newData) // Change int to long long
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    
    // Set the next pointer of the new node to the current first node
    newNode->next = *first;

    // Set the new node as the first node
    *first = newNode;
}


void addlast(struct node **start, long long newdata) // Change int to long long
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;

    // Check if the list is empty
    if (*start == NULL)
    {
        *start = newnode;
    }
    else
    {
        struct node *current = *start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}

// function to add numbers to node of linked list from array
struct node *addnumbers(long long number1[], int size_of_chain) // Change int to long long
{
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));

    first->data = number1[size_of_chain - 1];
    first->next = NULL;
    for (int i = 2; i <= size_of_chain; i++)
    {
        addlast(&first, number1[size_of_chain - i]);
    }
    return first;
}

struct node *add(int size_of_chain1, int size_of_chain2, struct node *first1, struct node *first2)
{
    int size_of_chain = 0;
    int size_diff = 0;
    if (size_of_chain1 > size_of_chain2)
    {
        size_diff = size_of_chain1 - size_of_chain2;
        size_of_chain = size_of_chain1;  
        for (int i = 0; i < size_diff; i++)
        {
            addfirst(&first2, 0);
        }
    }
    if (size_of_chain1 < size_of_chain2)
    {
        size_diff = size_of_chain2 - size_of_chain1;
         size_of_chain = size_of_chain2;
        for (int i = 0; i < size_diff; i++)
        {
            addfirst(&first1, 0);
        }
    }
    else
    {
         size_of_chain = size_of_chain1;
    }

    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = (first1->data + first2->data) % 10;
    long long carry = (first1->data + first2->data) / 10; // Change int to long long
    first->next = NULL;

    for (int i = 1; i < size_of_chain; i++)
    {
        long long sum = (first1->next->data + first2->next->data + carry); // Change int to long long
        addlast(&first, sum % 10);
        carry = sum / 10;
        first1 = first1->next;
        first2 = first2->next;
    }
    // Check if there is a carry left after the loop
    if (carry > 0)
    {
        addlast(&first, carry);
    }
    return first;
}

struct node *subtract(int size_of_chain, struct node *first1, struct node *first2)
{
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));

    if (first1->data < first2->data)
    {
        first->data = first1->data - first2->data + 10;
        long long borrow = 1; 
        first1->next->data -= borrow;
    }
    else
    {
        first->data = first1->data - first2->data;
    }
    first->next = NULL;

    for (int i = 1; i < size_of_chain; i++)
    {
        if (first1->next->data < first2->next->data)
        {
            long long sub = first1->next->data - first2->next->data + 10; // Change int to long long
            addlast(&first, sub);
            long long borrow = 1; // Change int to long long
            first1->next->next->data -= borrow;
        }
        else
        {
            long long sub = first1->next->data - first2->next->data; // Change int to long long
            addlast(&first, sub);
        }
        first1 = first1->next;
        first2 = first2->next;
    }
    return first;
}

// with this process all operations can be performed !!
struct node *multiplication(int size_of_chain1, int size_of_chain2, struct node *first1, struct node *first2)
{
    int mul = 0;
    int u = size_of_chain1;
    int carry = 0;
    struct node *templist = first1;
    int zero_counter = 1;
    long long zero = 0;
    struct node *mulseries1 = NULL;
    struct node *mulseries2 = NULL;
  
    struct node *ans = NULL;
    for (int i = 0; i < size_of_chain1 + size_of_chain2; i++)
    {
        addlast(&mulseries2, 0);
    }

    for (int i = 0; i < size_of_chain2; i++)
    {   
        for (int j = 0; j < size_of_chain1 - 1; j++) // for digit other than the last digit of the upper number
        {
            mul = first1->data * first2->data + carry;
            if (mul > 9)
            {
                addlast(&mulseries1, mul % 10);
                carry = mul / 10;
            }
            else {
                addlast(&mulseries1,mul);
                carry = 0;
            }
            first1= first1->next;
            
        }
            // for the last digit
    mul = first1->data * first2->data + carry;
    if (mul > 9)
    {
        addlast(&mulseries1, mul % 10);
        carry = mul / 10;
        //adding zero at starting
        for (int k = 1; k < u; k++)
        {
            addlast(&mulseries1, 0);
        }
        u--;
    }
    else
    {
        addlast(&mulseries1, mul);
        carry = 0;
        for (int k = 0; k < u; k++)
        {
            addlast(&mulseries1,zero );
        }
        u--;
    } 
    zero_counter =zero_counter+1;
    first1 = templist;
    first2 = first2->next;
    
    mulseries2 = add(size_of_chain1 + size_of_chain2, size_of_chain1 + size_of_chain2, mulseries1, mulseries2);
    mulseries1 = NULL;
    //adding zero at last 
    for (int k = 1; k < zero_counter; k++)
    {
        addlast(&mulseries1, zero);
    }
}
return mulseries2;
}

// struct node *exponentiation(int size_of_chain1,int size_of_chain2, struct node *first1, struct node *first2)
// {
//     struct node*ans = NULL;
//     long long sum_of_placevalues1 = 0;
//     long long sum_of_placevalues2 = 0;
//     long long exp_value = 1;
//     // getting actual numbers
//     //first number is base number
//     for (int i = 0,j = 1; i < size_of_chain1; i++, j = j*10)
//     {
//         sum_of_placevalues1 = sum_of_placevalues1  + first1->data * j;
//         first1 = first1->next;
//     }
//     //2nd number is power
//     for (int i = 0,j =1 ; i < size_of_chain2; i++, j = j*10)
//     {
//         sum_of_placevalues2 = sum_of_placevalues2 + first2->data*j ;
//         first2 = first2->next;
//     }
//     for (int i = 0; i < sum_of_placevalues2; i++)
//     {
//         exp_value = exp_value*sum_of_placevalues1;
//     }
//     while (exp_value> 0)
//     {
//         addlast(&ans,exp_value%10);
//         exp_value = exp_value/10;
//     }    
//     return ans;
// }

void main()
{
    long long number1[] = {6,4}; // Change int to long long
    long long number2[] = {5,1}; // Change int to long long
    int size_of_chain1 = sizeof(number1) / sizeof(number1[0]);
    int size_of_chain2 = sizeof(number2) / sizeof(number2[0]);

    int size_diff = 0;
    int add_size = 0;

    struct node *head = addnumbers(number1, size_of_chain1);

    struct node *head2 = addnumbers(number2, size_of_chain2);

    if (size_of_chain1 > size_of_chain2)
    {
        size_diff = size_of_chain1 - size_of_chain2;
        add_size = size_of_chain1;  
        for (int i = 0; i < size_diff; i++)
        {
            addfirst(&head2, 0);
        }
    }
    if (size_of_chain1 < size_of_chain2)
    {
        size_diff = size_of_chain2 - size_of_chain1;
        add_size = size_of_chain2;
        for (int i = 0; i < size_diff; i++)
        {
            addfirst(&head, 0);
        }
    }
    else
    {
        add_size = size_of_chain1;
    }
    printf("first linked list is : \n");
    traverseReverse(head);

    printf("\nsecond linked list is : \n");
    traverseReverse(head2);

    printf("\naddition linked list is \n");
    struct node *head3 = add(size_of_chain1,size_of_chain2,head,head2);
    traverseReverse(head3);

    printf("\nsubtraction linked list is \n");
    struct node *head4 = subtract(add_size ,head,head2);
    traverseReverse(head4);

    printf("\nmultiplication linked list is \n");
    struct node *head5 = multiplication(size_of_chain1, size_of_chain2, head, head2);
    traverseReverse(head5);

    // printf("\nexponentiation linked list is \n");
    // struct node *head6 = exponentiation(size_of_chain1, size_of_chain2, head, head2);
    // traverseReverse(head6);
}


