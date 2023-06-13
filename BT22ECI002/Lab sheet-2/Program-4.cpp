/*The worst-case scenario for the QuickSort algorithm occurs,
 when the chosen pivot element is either the smallest or
  largest element in the giver array for each recursive partition.
   This leads to an unbalanced partitioning and results in a 
   time complexity of O(n^2) instead of the average case 
   time complexity of O(n log n). 
   Here's an example demonstrating the worst-case scenario for QuickSort:*/

#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
 
    while (true){
        while (i <= j && A[i] <= pivot){
            i++;
        }
        while (A[j] >= pivot && j >= i){
            j--;
        }
        if (j < i){
            break;
        } else {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSort(int A[], int low, int high){
    if (low < high){
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}
 
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
