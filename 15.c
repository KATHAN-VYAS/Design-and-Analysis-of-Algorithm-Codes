/*
given A array with n entries . each entry holds different number .
there is some index p where in array values increase till p and then desceases till n
find peak entry by reading as few entries of array as possible
read at most entries O(log n)
*/

/*
approach : divide and conqure

1. look for mid element
2. check for mid-1 value and mid+1:
    if mid-1 > mid and mid+1 <mid:
        start = mid
        mid = (start+mid)/2
    if mid-1<mid and mid+1 >mid:
        end = mid
        mid = (end + mid)/2
    if mid is greates in mid-1 and mid +1:
        return mid

*/

#include <stdio.h>

void find_p(int array[], int start, int end)
{
    if (start == end)
    {
        printf("Peak value is: %d\n", array[start]);
        return;
    }

    int mid = start + (end - start) / 2;

    if (array[mid] > array[mid + 1])
        find_p(array, start, mid);
    else
        find_p(array, mid + 1, end);
}

int main()
{
    int n = 0;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    find_p(array, 0, n - 1);

    return 0;
}
