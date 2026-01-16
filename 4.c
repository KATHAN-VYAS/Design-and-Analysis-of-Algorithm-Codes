//quick sort - choose pivot element - smaller on left and larger on right
#include <stdio.h>

void quick_sort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);

int main() {
    int a[] = {1, 4, 74, 2, 23, 12};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quick_sort(a, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void quick_sort(int a[], int lb, int ub) {
    int loc;
    if (lb < ub) {
        loc = partition(a, lb, ub);
        quick_sort(a, lb, loc - 1);
        quick_sort(a, loc + 1, ub);
    }
}

int partition(int a[], int lb, int ub) {
    int pivot = a[ub];
    int i = lb - 1;// initialy pointer at outside of array
    //to check for smaller elements then pivot
    for (int j = lb; j <= ub - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            // Swap a[i] and a[j]
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // Swap a[i + 1] and a[ub] (pivot) [to set pivot in middle]
    int temp = a[i + 1];
    a[i + 1] = a[ub];
    a[ub] = temp;
    //returns index of pivot 
    return i + 1;
}
