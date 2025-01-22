#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
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

        // Node with two children
        Node* temp = findMin(root->right); // Inorder successor
        root->data = temp->data;          // Copy successor's value
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL){
       return;
    }    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL){
         return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL){
         return;
    }     
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool search(Node* root, int key) {
    if (root == NULL){
         return false;
    }
    if (root->data == key){
         return true;
    }     
    if (key < root->data){
       return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 20);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;

    int searchValue1 = 40;
    int searchValue2 = 90;

    cout << "Searching for " << searchValue1 << ": ";
    if (search(root, searchValue1))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Searching for " << searchValue2 << ": ";
    if (search(root, searchValue2))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    int deleteValue = 30;
    cout << "Deleting " << deleteValue << endl;
    root = deleteNode(root, deleteValue);

    cout << "In-order Traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
