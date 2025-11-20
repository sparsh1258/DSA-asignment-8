#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// INSERT (no duplicates)
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    else
        cout << "Duplicate value not allowed.\n";

    return root;
}

// FIND MINIMUM NODE (for delete)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// DELETE NODE
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// MAXIMUM DEPTH (height of tree)
int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// MINIMUM DEPTH
int minDepth(Node* root) {
    if (root == NULL)
        return 0;

    // If one child is missing, take depth of the other
    if (!root->left)
        return minDepth(root->right) + 1;

    if (!root->right)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// INORDER DISPLAY (optional)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, x;

    while (1) {
        cout << "\n--- BST OPERATIONS ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Maximum Depth\n";
        cout << "4. Minimum Depth\n";
        cout << "5. Display Inorder\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> x;
            root = insert(root, x);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> x;
            root = deleteNode(root, x);
            break;

        case 3:
            cout << "Maximum Depth = " << maxDepth(root) << endl;
            break;

        case 4:
            cout << "Minimum Depth = " << minDepth(root) << endl;
            break;

        case 5:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
