#include <iostream>
using namespace std;

// Heapify for MAX HEAP (used for increasing order)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Heapify for MIN HEAP (used for decreasing order)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Heapsort for increasing order (Max-Heap)
void heapSortIncreasing(int arr[], int n) {
    // Build Max-Heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

// Heapsort for decreasing order (Min-Heap)
void heapSortDecreasing(int arr[], int n) {
    // Build Min-Heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

// Display function
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 12, 35, 15, 10, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Increasing Order
    heapSortIncreasing(arr, n);
    cout << "Heapsort (Increasing Order): ";
    printArray(arr, n);

    // Restore array for decreasing order example
    int arr2[] = {20, 12, 35, 15, 10, 80};

    heapSortDecreasing(arr2, n);
    cout << "Heapsort (Decreasing Order): ";
    printArray(arr2, n);

    return 0;
}
