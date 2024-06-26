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

struct Node* findUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current;

    while (list1 != NULL) {
        insertRear(&result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        current = result;
        int found;
        while (current != NULL) {
            found=0;
            if (current->data == list2->data) {
                found = 1;
                break;
            }
            current = current->next;
        }
        if (!found) {
            insertRear(&result, list2->data);
        }
        list2 = list2->next;
    }

    return result;
}

struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL) {
        struct Node* current = list2;
        while (current != NULL) {
            if (list1->data == current->data) {
                insertRear(&result, list1->data);
                break;
            }
            current = current->next;
        }
        list1 = list1->next;
    }

    return result;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    printf("Enter elements for List 1 (one per line, type n to finish)");
    while (1) {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
        data = atoi(input);
        insertRear(&list1, data);
    }

    printf("Enter elements for List 2 (one per line, type n to finish)");
    while (1) {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            break;
        }
        data = atoi(input);
        insertRear(&list2, data);
    }
    struct Node* unionResult = findUnion(list1, list2);
    struct Node* intersectionResult = findIntersection(list1, list2);
    printf("Union of the lists:\n");
    traverseList(unionResult);
    printf("Intersection of the lists:\n");
    traverseList(intersectionResult);
    return 0;
}
