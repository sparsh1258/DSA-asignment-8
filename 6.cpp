#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Insert an element (push)
    void push(int val) {
        if (size == 100) {
            cout << "Overflow\n";
            return;
        }
        arr[size] = val;
        int i = size;
        size++;

        // Up-heapify
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Remove highest priority (pop)
    void pop() {
        if (size == 0) {
            cout << "Underflow\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    // Heapify (down-heapify)
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Return highest priority element
    int top() {
        if (size == 0) {
            cout << "Empty queue\n";
            return -1;
        }
        return arr[0];
    }

    // Display entire heap (optional)
    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(20);

    cout << "Priority Queue (Heap): ";
    pq.display();

    cout << "Top Element = " << pq.top() << endl;

    pq.pop();
    cout << "After deleting highest priority: ";
    pq.display();

    return 0;
}
