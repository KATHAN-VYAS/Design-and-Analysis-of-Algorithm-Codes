/*
need to obtain liscence for n algorithms
they can only obtain these liscence at the rate of at most one/month
each lisence price = $100
they are becoming more expensive according to exponential growth curves
cost of liscence j increase by factor Rj>1 each month, Rj is given parameter 
ie ; license is purchased t months from now then cost = 100 Rj t
all price gowth rate are distinct
Ri != Rj for i!=j (even they start at same price)
company can buy 1 license per month in which order company should buy license to minimize cost
algorithm takes n number of growth rates r1,r2,r3,r4... and compute the order to buy 

*/

/*  algorihtm 
1.ask for number of licese required 
2.set each algorithm price = 100
3.take growth rate of each and sort (quich sort)
4.buy as per sorted array

*/
#include <stdio.h>

// Structure to hold license information
struct License {
    int id;
    float growth_rate;
};

// Swap function for quicksort
void swap(struct License* a, struct License* b) {
    struct License t = *a;
    *a = *b;
    *b = t;
}

// Partition function for quicksort
int partition(struct License arr[], int low, int high) {
    float pivot = arr[high].growth_rate;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].growth_rate > pivot) { // Change here for descending order
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(struct License arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void buy_licenses(struct License licenses[], int n) {
    // Sort licenses by growth rate
    quickSort(licenses, 0, n - 1);

    // Print order to buy licenses
    printf("Order to buy licenses: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", licenses[i].id);
    }
}

int main() {
    int n;
    printf("Enter the number of licenses: ");
    scanf("%d", &n);

    struct License licenses[n];
    printf("Enter the growth rates for each license:\n");
    for(int i = 0; i < n; i++) {
        licenses[i].id = i+1;
        printf("License %d: ", i + 1);
        scanf("%f", &licenses[i].growth_rate);
    }

    buy_licenses(licenses, n);

    return 0;
}

