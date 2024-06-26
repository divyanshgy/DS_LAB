#include <stdio.h>
#include <stdlib.h>

struct User {
    int id;
    int time;
    struct User* next;
    struct User* prev;
};

struct User* createUser(int id, int time) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    newUser->id = id;
    newUser->time = time;
    newUser->next = newUser;
    newUser->prev = newUser;
    return newUser;
}

void insertAfter(struct User* user, struct User* newUser) {
    newUser->next = user->next;
    newUser->prev = user;
    user->next->prev = newUser;
    user->next = newUser;
}


void removeUser(struct User* user) {
    user->prev->next = user->next;
    user->next->prev = user->prev;
    free(user);
}


void displayQueue(struct User* start) {
    struct User* current = start->next;
    printf("Queue: ");
    while (current != start) {
        printf("User%d(%d min) -> ", current->id, current->time);
        current = current->next;
    }
}

int main() {
    struct User* queue = createUser(0, 0);

    int userId = 1;
    int choice;

    while (1) {
        printf("1. Book a washing machine\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int time;
            printf("Enter booking time (minutes): ");
            scanf("%d", &time);

            struct User* newUser = createUser(userId, time);
            insertAfter(queue->prev, newUser);
            userId++;

            displayQueue(queue);

            while (queue->next != queue) {
                struct User* currentUser = queue->next;
                printf("User%d is using the washing machine for %d minutes\n", currentUser->id, currentUser->time);
                currentUser->time--;

                if (currentUser->time <= 0) {
                    printf("User%d has completed their laundry\n", currentUser->id);
                    removeUser(currentUser);
                }
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(queue);

    return 0;
}
