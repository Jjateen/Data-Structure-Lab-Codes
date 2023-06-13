#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the partition index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// Function to find the kth smallest element using QuickSort
int findKthSmallest(int arr[], int n, int k) {
    quickSort(arr, 0, n - 1);
    return arr[k - 1];
}

int main() {
    int arr[] = { 7, 10, 4, 3, 20, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int kthSmallest = findKthSmallest(arr, n, k);

    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    return 0;
}
