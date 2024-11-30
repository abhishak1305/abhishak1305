#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;  // Store the data of the node
    Node* next;  // Pointer to the next node in the list
};

// Push a new element onto the stack
void push(Node*& top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;  // Point the new node to the current top
    top = newNode;  // Move the top pointer to the new node
    cout<<"pushed: "<<top->data<<endl;
}

// Pop the top element from the stack
int pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;  // Return an invalid value if the stack is empty
    }
    Node* temp = top;  // Store the current top node temporarily
    int poppedValue = top->data;  // Get the value to return
    top = top->next;  // Move the top pointer to the next node
    delete temp;  // Delete the old top node to free memory
    return poppedValue;
}

// Peek the top element of the stack without removing it
int peek(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return -1;  // Return an invalid value if the stack is empty
    }
    return top->data;  // Return the top element's value
}

// Check if the stack is empty
bool isEmpty(Node* top) {
    return top == nullptr;  // Stack is empty if top is null
}

// Display the contents of the stack
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;  // Start from the top of the stack
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    }
    cout<< endl;  // End of stack
}

// Main function to test the stack
int main() {
    Node* stack = nullptr;  // Initialize an empty stack (top is null)

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);  // Output: 30 -> 20 -> 10 -> None

    cout << "Top element: " << peek(stack) << endl;  // Output: 30

    cout << "Popped element: " << pop(stack) << endl;  // Output: 30
    display(stack);  // Output: 20 -> 10 -> None

    return 0;
}
