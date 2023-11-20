#include <stdio.h>
#include <stdlib.h>
int *queue;
int front = -1;
int rear = -1;
int size;
void initializeQueue();
int isFull();
int isEmpty();
void enqueue(int element);
int dequeue();
int searchElement(int element);
void displayQueue();

int main() {
    int choice, element, searchResult;

    printf("Enter the size of the Circular Queue: ");
    scanf("%d", &size);

    initializeQueue();

    do {
 
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Search \n");
        printf("4. Display \n");
        printf("0. Exit\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(element);
                if (searchResult != -1) {
                    printf("%d found at position %d\n", element, searchResult);
                } else {
                    printf("%d not found in the queue\n", element);
                }
                break;

            case 4:
                displayQueue();
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    free(queue);

    return 0;
}


void initializeQueue() {
    queue = (int *)malloc(size * sizeof(int));
}


int isFull() {
    return (front == (rear + 1) % size);
}
int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", element);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = element;
    printf("%d enqueued \n", element);
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    element = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("%d dequeued\n", element);
    return element;
}
int searchElement(int element) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot search\n");
        return -1;
    }

    int current = front;
    int position = 1;

    do {
        if (queue[current] == element) {
            return position;
        }

        current = (current + 1) % size;
        position++;
    } while (current != (rear + 1) % size);

    return -1;  
}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int current = front;

    do {
        printf("%d ", queue[current]);
        current = (current + 1) % size;
    } while (current != (rear + 1) % size);

    printf("\n");
}

