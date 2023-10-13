#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform in-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a node with a given key
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Function to find the node with the minimum value in the tree
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given key from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data, key;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. In-order traversal\n");
        printf("3. Search for a node\n");
        printf("4. Delete a node\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Node with data %d found in the tree.\n", key);
                } else {
                    printf("Node with data %d not found in the tree.\n", key);
                }
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}