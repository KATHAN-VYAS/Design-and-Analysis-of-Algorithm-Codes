//insertion sort - pivot(humble elements)

# include<stdio.h>

void main()
{
    int numbers[] = {4, 14,2, 56, 1, 10};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    printf("entered array: "); 
    for(int i =0 ; i<length -1; i ++)
    {
        printf("%d, ",numbers[i]);   
    }
    printf("%d \n",numbers[length-1]);
    //swaping with smaller element
    for(int i = 1; i<length; i ++)
    {
        for(int j = 0;j <i; j ++)
        {
            if(numbers[i]<numbers[j])
            {
                int temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i]= temp;
            }
            else{
                continue;
            }
        }
    }
    printf("sorted array: "); 
    for(int i =0 ; i<length -1; i ++)
    {
        printf("%d, ",numbers[i]);   
    }
    printf("%d \n",numbers[length-1]);
}
//2nd 

// for(j = 2 ; j<length; j++)
// {
//     pivot = a[j];
//     i = j-1;
//     while (i > 0 &a[i]>pivot)
//     {
//         a[i+1] = a[i];
//         i = i-1;
//         a[i+1] = pivot;
//     }
// }