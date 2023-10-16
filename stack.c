#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int linearSearch(struct Stack* stack, int target) {
    struct Node* current = stack->top;
    int position = 1;

    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void displayStack(struct Stack* stack) {
    printf("Stack: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = initializeStack();
    int value, position, target;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Linear Search\n");
        printf("4. Display Stack\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                if (!isEmpty(stack)) {
                    printf("Popped: %d\n", pop(stack));
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 3:
                printf("Enter the target value to search: ");
                scanf("%d", &target);
                position = linearSearch(stack, target);
                if (position != -1) {
                    printf("%d found at position %d\n", target, position);
                } else {
                    printf("%d not found in the stack\n", target);
                }
                break;
            case 4:
                displayStack(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
