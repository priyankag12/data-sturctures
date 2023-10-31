#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
         exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Initialize as a self-referencing node.
    return newNode;
}

struct Node *createCircularList() {
    int n, data;
    struct Node *head = NULL;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

void insertNode(struct Node **head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    if (position == 0) {
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
        } else {
            struct Node *temp = *head;
            for (int i = 0; i < position - 1; i++) {
                if (temp->next == *head) {
                    printf("Invalid position for insertion.\n");
                    free(newNode);
                    return;
                }
                temp = temp->next;
            }
                newNode->next = temp->next;
                temp->next = newNode;
        }
}

void deleteNode(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
        }
        struct Node *current = *head, *prev = NULL;
        while (current->data != key) {
            if (current->next == *head) {
                printf("Element not found in the list.\n");
                return;
                }
                prev = current;
                current = current->next;
            }
            if (current->next == *head && prev == NULL) {
                *head = NULL;
                free(current);
                return;
            }
            if (current == *head) {
                struct Node *temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                *head = current->next;
                temp->next = *head;
            } else {
                prev->next = current->next;
        }
        free(current);
}
void reverseList(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *prev = NULL, *current = *head, *next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    (*head)->next = prev;
    *head = prev;
}
void concatenateLists(struct Node **list1, struct Node *list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    if (list2 == NULL) {
        return;
    }
    struct Node *temp = *list1;
    while (temp->next != *list1) {
        temp = temp->next;
    }
    temp->next = list2;
    temp = list2;
    while (temp->next != list2) {
        temp = temp->next;
    }
    temp->next = *list1;
}
void displayList(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (Back to head)\n");
}
int main() {
    struct Node *head = NULL;
    struct Node *list2 = NULL;
    int choice, data, position, key;
    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create a list\n");
        printf("2. Insert a node\n");
        printf("3. Delete a node\n");
        printf("4. Reverse the list\n");
        printf("5. Concatenate two lists\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               head = createCircularList();
               break;
            case 2:
               printf("Enter data to insert: ");
               scanf("%d", &data);
               printf("Enter position for insertion (0 for beginning): ");
               scanf("%d", &position);
               insertNode(&head, data, position);
               break;
            case 3:
               printf("Enter the key to delete: ");
               scanf("%d", &key);
               deleteNode(&head, key);
               break;
            case 4:
               reverseList(&head);
               break;
            case 5:
               list2 = createCircularList();
               concatenateLists(&head, list2);
               break;
            case 6:
               displayList(head);
               break;
            case 7:
               exit(0);
            default:
               printf("Invalid choice. Please try again.\n");
        }      
    }
    return 0;
}