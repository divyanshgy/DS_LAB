#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node with data before a specific element in the list
void insertBefore(struct Node** head, int element, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == element) {
            if (prev == NULL) {
                newNode->next = *head;
                *head = newNode;
            } else {
                prev->next = newNode;
                newNode->next = current;
            }
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Element not found.\n");
}

// Function to insert a new node with data after a specific element in the list
void insertAfter(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node is NULL.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a given element from the list
void deleteElement(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to sort the linked list (bubble sort)
void sort(struct Node* head) {
    struct Node* current;
    int temp;
    int swapped;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Function to delete every alternate node in the list
void deleteAlternateNodes(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

// Function to insert an element in a sorted list while maintaining order
void insertSorted(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data < newData) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    int element, newData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert before an element\n");
        printf("2. Insert after an element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                printf("Enter the new data to insert: ");
                scanf("%d", &newData);
                insertBefore(&head, element, newData);
                break;

            case 2:
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                printf("Enter the new data to insert: ");
                scanf("%d", &newData);
                insertAfter(head, newData);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                reverse(&head);
                break;

            case 6:
                sort(head);
                break;

            case 7:
                deleteAlternateNodes(head);
                break;

            case 8:
                printf("Enter the data to insert in the sorted list: ");
                scanf("%d", &newData);
                insertSorted(&head, newData);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

