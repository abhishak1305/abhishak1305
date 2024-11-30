#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Insert function to insert nodes into the BST
Node* insert(Node* root, int item) {
    Node* n = new Node;
    n->data = item;
    n->left = NULL;
    n->right = NULL;

    if (root == NULL) {
        return n;
    }

    if (item < root->data) {
        root->left = insert(root->left, item);
    } else if (item > root->data) {
        root->right = insert(root->right, item);
    }

    return root;
}

// Function to search a node by item
Node* search(Node* root, int item) {
    if (root == NULL || root->data == item) {
        return root;
    }
    if (item < root->data) {
        return search(root->left, item);
    } else {
        return search(root->right, item);
    }
}

// Find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int item) {
    if (root == NULL) {
        return root;
    }

    if (item < root->data) {
        root->left = deleteNode(root->left, item);
    } else if (item > root->data) {
        root->right = deleteNode(root->right, item);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


// In-order traversal
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void preorder(struct node *r) {
    if (r != NULL) {
        cout << r->data << "\t";
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
    }
}

int main() {
    Node* root = NULL;
    int n, data, item;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    // Insert nodes into the BST
    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        root = insert(root, data);
    }
    cin>>item;
    // Delete nodes
    root = deleteNode(root,item);

    cout << "In-order Traversal after deletion: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
