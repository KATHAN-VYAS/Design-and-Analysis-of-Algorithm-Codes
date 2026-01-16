// merge sort - divide and conqure
#include <stdio.h>

void merge(int a[], int lb, int mid, int ub);
void merge_sort(int a[], int lb, int ub);
int main() {
    int a[] = {1, 4, 74, 2, 23, 12};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    merge_sort(a, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}


void merge_sort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;// pointer for 1st array 
    int j = mid + 1;// pointer for 2nd array
    int k = lb;
    int b[ub + 1]; // New array to store the merged result

    //3 conditions from adding elements from parts of arrays
    //when both subarray satisfies condition
    //add smallest among them to new array
    while (i <= mid && j <= ub) {
        // making 2 pointers to arrays i and j
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    //when only left subarray satisfies
    while (i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }
    //when only right array satisfies
    while (j <= ub) {
        b[k] = a[j];
        k++;
        j++;
    }
    //coping elements to origianl array
    for (k = lb; k <= ub; k++) {
        a[k] = b[k];
    }
}

//2nd code 

// #include <stdio.h>
// #include <stdlib.h>

// void conquer(int arr[], int si, int mid, int ei)
// {
//     int* merged = (int*)malloc((ei - si + 1) * sizeof(int));
//     int idx1 = si;
//     int idx2 = mid + 1;
//     int x = 0;

//     while (idx1 <= mid && idx2 <= ei)
//     {
//         if (arr[idx1] <= arr[idx2])
//         {
//             merged[x] = arr[idx1];
//             x++;
//             idx1++;
//         }
//         else
//         {
//             merged[x] = arr[idx2];
//             x++;
//             idx2++;
//         }
//     }

//     // Copy remaining elements from the left subarray
//     while (idx1 <= mid)
//     {
//         merged[x] = arr[idx1];
//         x++;
//         idx1++;
//     }

//     // Copy remaining elements from the right subarray
//     while (idx2 <= ei)
//     {
//         merged[x] = arr[idx2];
//         x++;
//         idx2++;
//     }

//     // Copy sorted array back to the original array
//     for (int i = 0, j = si; i < (ei - si + 1); i++, j++)
//     {
//         arr[j] = merged[i];
//     }

//     free(merged); // Free the allocated memory
// }

// void divide(int arr[], int si, int ei)
// {
//     if (si < ei)
//     {
//         int mid = si + (ei - si) / 2;
//         divide(arr, si, mid);
//         divide(arr, mid + 1, ei);
//         conquer(arr, si, mid, ei);
//     }
// }

// int main()
// {
//     int arr[] = {4, 21, 75, 12, 23, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     divide(arr, 0, n - 1);
    
//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }
