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

void deleteRear(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* current = *head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position");
        return;
    }
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        struct Node* current = *head;
        int currentPosition = 1;
        while(currentPosition<position-1&&current!=NULL){
            current = current->next;
            currentPosition++;
        }
        if (current==NULL) {
            printf("Invalid position");
            free(newNode);
            return;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        newNode->prev = current;
        current->next = newNode;
    }
}
void deleteAtPosition(struct Node** head,int position) {
    if(*head==NULL){
        printf("The list is empty");
        return;
    }
    if(position<1){
        printf("Invalid position");
        return;
    }
    if(position==1){
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
    else{
        struct Node* current = *head;
        int count = 1;
        while (count < position && current != NULL) {
            current = current->next;
            count++;
        }
        if (current==NULL) {
            printf("Invalid position");
            return;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
}
void insertAfterElement(struct Node** head, int data, int element) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            struct Node* newNode = createNode(data);
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            newNode->prev = current;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element not found");
}
void insertBeforeElement(struct Node** head, int data, int element) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            struct Node* newNode = createNode(data);
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head = newNode;
            }
            newNode->next = current;
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element not found");
}

void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Insert at the rear end\n");
        printf("2. Delete from the rear end\n");
        printf("3. Insert at a given position\n");
        printf("4. Delete from a given position\n");
        printf("5. Insert after another element\n");
        printf("6. Insert before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the rear end: ");
                scanf("%d", &data);
                insertRear(&head, data);
                break;
            case 2:
                deleteRear(&head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter element to insert after: ");
                scanf("%d", &element);
                insertAfterElement(&head, data, element);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter element to insert before: ");
                scanf("%d", &element);
                insertBeforeElement(&head, data, element);
                break;
            case 7:
                traverseList(head);
                break;
            case 8:
                reverseList(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Try again");
        }
    }

    return 0;
}
