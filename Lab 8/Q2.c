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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertRear(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void concatenateLists(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }

    struct Node* current = *X1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = X2;
    X2->prev = current;
}
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty");
        return;
    }
        while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;
    int choice, data;

    printf("Enter elements for X1,enter n to exit");
    while (1) {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
        data = atoi(input);
        insertRear(&X1, data);
    }

    printf("Enter elements for X2,enter n to exit");
    while (1) {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
        data = atoi(input);
        insertRear(&X2, data);
    }
    concatenateLists(&X1, X2);
    printf("Concatenated List:\n");
    traverseList(X1);
    return 0;
}
