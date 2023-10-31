#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* ptr = NULL;
    while (current != NULL && current->data != key) {
        ptr = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found in the list.\n");
    }
    if (ptr == NULL) {
        *head = current->next;
    } else {
        ptr->next = current->next;
    }
    free(current);
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void bubbleSort(struct Node** head) {
    int swapped, temp;
    struct Node* current;
    struct Node* lptr = NULL;

    if (*head == NULL) {
        return;
    }
    do {
        swapped = 0;
        current = *head;
        while (current->next != lptr) {
            if (current->data > current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);
}

void unionLists(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
        return;
    }
    struct Node* current = *list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *list2;
}

void intersectionLists(struct Node** list1, struct Node** list2) {
    struct Node* current1 = *list1;
    struct Node* prev1 = NULL;

    while (current1 != NULL) {
        int data = current1->data;
        struct Node* current2 = *list2;
        struct Node* prev2 = NULL;
        int found = 0;
        while (current2 != NULL) {
            if (current2->data == data) {
                found = 1;
                break;
            }
            prev2 = current2;
            current2 = current2->next;
        }
        if (!found) {
            if (prev1 == NULL) {
                *list1 = current1->next;
            } else {
                prev1->next = current1->next;
            }
            free(current1);
            current1 = prev2;
        }
        prev1 = current1;
        current1 = current1->next;
    }
}

void concatenate(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
        return;
    }
    struct Node* current = *list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *list2;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int choice;
    int data;

    do {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Reverse list\n");
        printf("5. Bubble Sort\n");
        printf("6. Union of lists\n");
        printf("7. Intersection of lists\n");
        printf("8. Concatenate lists\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&list1, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&list1, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&list1, data);
                break;
            case 4:
                reverse(&list1);
                printf("List reversed.\n");
                break;
            case 5:
                bubbleSort(&list1);
                printf("List sorted using bubble sort.\n");
                break;
            case 6:
                printf("Enter data for list 2: ");
                scanf("%d", &data);
                insertAtEnd(&list2, data);
                printf("Union of lists.\n");
                unionLists(&list1, &list2);
                list2 = NULL; // Set list2 to NULL after union
                break;
            case 7:
                printf("Enter data for list 2: ");
                scanf("%d", &data);
                insertAtEnd(&list2, data);
                printf("Intersection of lists.\n");
                intersectionLists(&list1, &list2);
                break;
            case 8:
                printf("Enter data for list 2: ");
                scanf("%d", &data);
                insertAtEnd(&list2, data);
                printf("Concatenating lists.\n");
                concatenate(&list1, &list2);
                list2 = NULL; // Set list2 to NULL after concatenation
                break;
            case 9:
                printf("List: ");
                display(list1);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
	while (choice != 10);
    // Free memory before exiting
    struct Node* current = list1;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);   
    }
    return 0;  
}



