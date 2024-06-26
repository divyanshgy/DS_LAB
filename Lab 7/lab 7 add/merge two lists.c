#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, set the new node as the head
        *head = newNode;
    } else {
        // Otherwise, insert the node at the end of the list
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to merge two sorted linked lists X and Y into Z
struct Node* mergeSortedLists(struct Node* X, struct Node* Y) {
    struct Node* Z = NULL;
    struct Node* tail = NULL;

    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            if (Z == NULL) {
                Z = X;
                tail = X;
            } else {
                tail->next = X;
                tail = X;
            }
            X = X->next;
        } else {
            if (Z == NULL) {
                Z = Y;
                tail = Y;
            } else {
                tail->next = Y;
                tail = Y;
            }
            Y = Y->next;
        }
    }

    if (X != NULL) {
        tail->next = X;
    } else if (Y != NULL) {
        tail->next = Y;
    }

    return Z;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Linked List (Z): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X = NULL;
    struct Node* Y = NULL;

    int newData;
    char choice;

    printf("Enter elements for list X (in non-decreasing order):\n");
    do {
        printf("Enter a number (or type 'done' to finish): ");
        scanf("%d", &newData);
        if (newData != -1) {
            insertNode(&X, newData);
        }
    } while (newData != -1);

    printf("Enter elements for list Y (in non-decreasing order):\n");
    do {
        printf("Enter a number (or type 'done' to finish): ");
        scanf("%d", &newData);
        if (newData != -1) {
            insertNode(&Y, newData);
        }
    } while (newData != -1);

    struct Node* Z = mergeSortedLists(X, Y);

    printf("Merged List (Z): ");
    displayList(Z);

    return 0;
}

