#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertElement(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void deleteElement(struct Node** head, int data) {
    if (*head == NULL) {
        printf("The list is empty");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    int found = 0;

    do {
        if (current->data == data) {
            if (current == *head) {
                *head = current->next;
            }
            if (prev != NULL) {
                prev->next = current->next;
                current->next->prev = prev;
            }

            free(current);
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (found) {
        printf("Element %d deleted successfully", data);
    } else {
        printf("Element %d not found in the list", data);
    }
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d\t", current->data);
        current = current->next;
    } while (current != head);

}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertElement(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
