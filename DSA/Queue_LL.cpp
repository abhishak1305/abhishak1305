
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor for easy initialization
    Node(int val) : data(val), next(nullptr) {}
};

// Global pointers for front and rear of the queue
Node* front = nullptr;
Node* rear = nullptr;

// Function to check if the queue is empty
bool isEmpty() {
    return front == nullptr;
}

// Function to enqueue (add an element) to the queue
void enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        // If the queue is empty, both front and rear point to the new node
        front = rear = newNode;
    } else {
        // Otherwise, add the new node at the end and update the rear
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue (remove an element) from the queue
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;  // Return an error value
    }

    // Get the value of the front node
    int dequeuedValue = front->data;
    Node* temp = front;

    // Move front to the next node
    front = front->next;

    // If the queue becomes empty, set rear to null
    if (front == nullptr) {
        rear = nullptr;
    }

    // Delete the old front node
    delete temp;

    return dequeuedValue;
}

// Function to peek at the front element of the queue
int peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot peek." << endl;
        return -1;  // Return an error value
    }
    return front->data;
}

// Function to display the contents of the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Enqueue some elements
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display queue
    cout << "Queue after enqueue operations: ";
    display();

    // Dequeue an element
    cout << "Dequeued: " << dequeue() << endl;

    // Display queue after dequeue
    cout << "Queue after dequeue: ";
    display();

    // Peek at the front element
    cout << "Front element: " << peek() << endl;

    // Dequeue all elements
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;

    // Display queue after all dequeues
    cout << "Queue after all dequeues: ";
    display();

    return 0;
}
