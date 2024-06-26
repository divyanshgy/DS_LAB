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

// Recursive function to traverse and display the linked list
void traverseList(struct Node* current) {
    if (current == NULL) {
        // Base case: If the current node is NULL, stop the recursion
        return;
    }

    // Print the data of the current node
    printf("%d -> ", current->data);

    // Recursive call to traverse the next node
    traverseList(current->next);
}

int main() {
    struct Node* head = NULL;
    int newData;
    char choice;

    do {
        printf("Enter a number to insert into the linked list: ");
        scanf("%d", &newData);
        insertNode(&head, newData);
        printf("Do you want to insert another node (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Linked List: ");
    traverseList(head);
    printf("NULL\n");

    return 0;
}
