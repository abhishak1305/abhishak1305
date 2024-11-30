Bubble Sort
Insertion Sort
Selection Sort
Merge Sort
Quick Sort

#include <iostream>
using namespace std;

int partition(int a[], int s, int e) {
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (a[j] <= pivot) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(int a[], int s, int e,int x) {
    
    if (s >= e) {
        return;
    }

    int mid = partition(a, s, e);
    
    cout << "After iteration " <<++x<< ": ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quicksort(a, s, mid - 1,x);
    quicksort(a, mid + 1, e,x);
}

int main() {
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    cout << "Initial array: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int x=0;
    quicksort(a, 0, 4,x);
    
    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
