// You are using GCC
#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    int arr[100];
    int qfront=0;
    int rear=0;
    int size=5;

    bool isEmpty() {
        return (qfront == rear);
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is Full" << endl;
            return;
        } else {
            arr[rear] = data;
            cout<<"Order ID "<<arr[rear]<<" is inserted in the queue"<<endl;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear) {
            return -1;
        } else {
            cout<<"Processed Order ID: "<<arr[qfront]<<endl;
            int ans = arr[qfront];
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;
        } else {
            return arr[qfront];
        }
    }

    void traverse() {
        if (qfront == rear) {
            cout << "\nQueue is Empty\n";
            return;
        }
        int i = qfront;
        cout << "Order IDs in the queue are: ";
        while (i != rear) {
            cout << arr[i] << " ";
            i++;
        }
    }
} Q;

int main() {
    queue <int> q;
    int choice, item;
    while (true) {
        // cout << "\nEnter choice \n1. Enqueue \n2. Dequeue \n3. Traversing\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> item;
                Q.enqueue(item);
                break;
            case 2:
                if (Q.dequeue() == -1) {
                    cout << "\nQueue is Empty\n";
                }
                break;
            case 3:
                Q.traverse();
                break;
            case 4:
            cout<<"\nExiting the program\n";
                return 0;
            default:
                cout << "\nInvalid option\n";
        }
    }
    return 0;
}
