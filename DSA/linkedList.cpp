#include <iostream>
using namespace std;

// Node structure definition for the linked list
struct Node {
    int data;   // The data stored in the node
    Node* next; // Pointer to the next node in the list
};

// Function to add a node at the end of the list
void end(Node*& head, int item) {
    // Create a new node with the given item
    Node* n = new Node;
    n->data = item;
    n->next = nullptr; // This new node will be the last node, so next is nullptr

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = n;
    } else {
        // Traverse to the last node in the list
        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        // Link the last node to the new node
        ptr->next = n;
    }
}

// Function to traverse (print) the entire linked list
void traverse(Node* head) {
    Node* temp = head;
    // Traverse until the end of the list
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << endl; // Print a newline at the end
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int item, int position) {
    // Create a new node
    Node* n = new Node;
    n->data = item;
    n->next = nullptr;

    // If inserting at position 1, update head to the new node
    if (position == 1) {
        n->next = head; // Point the new node to the current head
        head = n; // Set the head to the new node
        return;
    }

    // Traverse to the node just before the desired position
    Node* ptr = head;
    int currentPosition = 1; // To track the current position in the list

    // Find the node just before the insertion position
    while (ptr != nullptr && currentPosition < position-1) {
        ptr = ptr->next;
        currentPosition++;
    }

    // If the position is out of range, return without inserting
    if (ptr == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Insert the new node after the found node
    n->next = ptr->next; // Point the new node to the next node of the current node
    ptr->next = n; // Point the current node to the new node
}

// Function to delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    // If the list is empty
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // If deleting the head node (position 1)
    if (position == 1) {
        Node* temp = head; // Temporarily store the head node
        head = head->next; // Move head to the next node
        delete temp; // Delete the old head
        return;
    }

    // Traverse to the node just before the one to be deleted
    Node* ptr = head;
    int currentPosition = 1;

    while (ptr != nullptr && currentPosition < position - 1) {
        ptr = ptr->next; // Move to the next node
        currentPosition++;
    }

    // If the position is out of range, print an error
    if (ptr == nullptr || ptr->next == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Node to be deleted is ptr->next
    ptr->next = ptr->next->next; // Skip the node to be deleted, effectively removing it
    // The node is deleted by letting it go out of scope, so no need for explicit delete here
}

// Function to delete the last node of the list
void deleteLastNode(Node*& head) {
    // If the list is empty
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // If the list has only one node
    if (head->next == nullptr) {
        delete head; // Delete the only node
        head = nullptr; // Now the list is empty
        return;
    }

    // Traverse to the second-to-last node
    Node* ptr = head;
    while (ptr->next != nullptr && ptr->next->next != nullptr) {
        ptr = ptr->next; // Move to the second-to-last node
    }

    // Delete the last node
    ptr->next = nullptr; // Set the second-to-last node's next pointer to nullptr
    // The last node is deleted when the pointer goes out of scope
}

int main() {
    Node* head = nullptr; // Initialize the head of the list as null (empty list)

    // Add some nodes to the list by calling 'end' function
    for (int i = 0; i < 5; i++) {
        int item;
        cin >> item; // Read an item to insert
        end(head, item); // Add it to the list
    }

    cout << "Original list: ";
    traverse(head); // Print the original list

    // Insert a node at a specific position
    int item, position;
    cout << "Enter item to insert: ";
    cin >> item;
    cout << "Enter position to insert at: ";
    cin >> position;
    insertAtPosition(head, item, position); // Insert the new node
    cout << "List after insertion: ";
    traverse(head); // Print the updated list

    // Delete a node at a specific position
    cout << "Enter position to delete from: ";
    cin >> position;
    deleteAtPosition(head, position); // Delete the node at the given position
    cout << "List after deletion: ";
    traverse(head); // Print the updated list after deletion

    // Delete the last node
    deleteLastNode(head); // Delete the last node
    cout << "List after deleting last node: ";
    traverse(head); // Print the list after deleting the last node

    return 0;
}
