#include <iostream>
using namespace std;

void heapify(int heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, size, largest);
    }
}

void buildHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

void insert(int heap[], int& size, int value) {
    heap[size] = value;
    size++;
    buildHeap(heap, size);
}

void deleteRoot(int heap[], int& size) {
    if (size <= 0) return; // No elements to delete
    heap[0] = heap[size - 1]; // Replace root with last element
    size--;
    heapify(heap, size, 0); // Restore heap property
}

void heapSort(int heap[], int n) {
    int size = n;
    buildHeap(heap, size); // Ensure the array is a valid heap first
    while (size > 1) {
        swap(heap[0], heap[size - 1]); 
        size--;
        heapify(heap, size, 0); // Restore heap property
    }
}

void printHeap(int heap[], int size) {
    cout << "Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int cap;
    cout << "Enter capacity to insert into the heap:\n";
    cin>>cap;
    
    int size = 0;
    int heap[100];

    cout << "Enter values to insert into the heap:\n";
    for (int i = 0; i < cap; i++) {
        int value;
        cin >> value;
        insert(heap, size, value);
    }

    printHeap(heap, size);

    cout << "\nSorting the heap...\n";
    heapSort(heap, size);
    printHeap(heap, size);

    return 0;
}
