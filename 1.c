//selection sort - unsorted array and min elements
#include <stdio.h>

int main()
{
    int numbers[] = {4, 14,2, 56, 1, 10};
    int length = sizeof(numbers) / sizeof(numbers[0]);
   //printing the array
    printf("entered array: "); 
    for(int i =0 ; i<length -1; i ++)
    {
        printf("%d, ",numbers[i]);   
    }
    printf("%d \n",numbers[5]);
    
for (int i = 0; i < length; i++)
{
    int min_index = i;
    //loop to find minimum element
    for (int j = i + 1; j < length; j++)
    {
        if (numbers[j] < numbers[min_index])
        {
            min_index = j;
        }
    }

    // Swap the found minimum element with the current element
    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
}


    printf("sorted array: "); 
    for(int i =0 ; i<length-1; i ++)
    {
        printf("%d, ",numbers[i]);
    }
    printf("%d",numbers[length -1]);

    return 0;
}

//2nd code
// for(int i =0; i<length-1; i ++)
// {
//     int min = i;
//     for(j = i +1; j<n;j ++)
//     {
//         if (numbers[j] = numbers[min]);
//         {
//             min = j;
//         }
//         if (min != i)
//         {
//             int temp = numbers[i];
//             numbers[i] = numbers[min];
//             numbers[min] = temp;
//         }
//     }
// }

