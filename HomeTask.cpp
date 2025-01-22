#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int id;
    char name[100];
    float cgpa;
    Node *left, *right;

    Node(int id, const char name[], float cgpa) {
        this->id = id;
        strcpy(this->name, name);
        this->cgpa = cgpa;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int id, const char name[], float cgpa) {
    if (root == NULL) {
        return new Node(id, name, cgpa);
    }

    if (id < root->id) {
        root->left = insertBST(root->left, id, name, cgpa);
    } else if (id > root->id) {
        root->right = insertBST(root->right, id, name, cgpa);
    }

    return root;
}


Node* searchBST(Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return searchBST(root->left, id);
    } else {
        return searchBST(root->right, id);
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << "ID: " << root->id << " Name: " << root->name << " CGPA: " << root->cgpa << endl;
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insertBST(root, 1, "Tanvir", 3.5);
    root = insertBST(root, 3, "Ahmed", 3.8);
    root = insertBST(root, 2, "Badhon", 3.7);
    root = insertBST(root, 4, "Md", 3.9);

    cout << "In-order Traversal of the BST:" << endl;
    inorder(root);

    int searchId = 3;
    Node* result = searchBST(root, searchId);
    if (result != NULL) {
        cout << "Student Found: ID = " << result->id << ", Name = " << result->name << ", CGPA = " << result->cgpa << endl;
    } else {
        cout << "Student with ID " << searchId << " not found." << endl;
    }

    return 0;
}
