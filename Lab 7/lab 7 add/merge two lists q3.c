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

// Function to merge two lists list1 and list2 into list3
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* list3 = NULL;
    struct Node* current1 = list1;
    struct Node* current2 = list2;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            insertNode(&list3, current1->data);
            current1 = current1->next;
        }
        if (current2 != NULL) {
            insertNode(&list3, current2->data);
            current2 = current2->next;
        }
    }

    return list3;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Merged List (list3): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int newData;
    char choice;

    printf("Enter elements for list1:\n");
    do {
        printf("Enter a number (or type 'done' to finish): ");
        scanf("%d", &newData);
        if (newData != -1) {
            insertNode(&list1, newData);
        }
    } while (newData != -1);

    printf("Enter elements for list2:\n");
    do {
        printf("Enter a number (or type 'done' to finish): ");
        scanf("%d", &newData);
        if (newData != -1) {
            insertNode(&list2, newData);
        }
    } while (newData != -1);

    struct Node* list3 = mergeLists(list1, list2);

    printf("Merged List (list3): ");
    displayList(list3);

    return 0;
}
