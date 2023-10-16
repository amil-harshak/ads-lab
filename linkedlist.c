#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return head;
    }

    if (position == 0) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head; // Changed 'current' to 'temp'
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head; // Changed 'current' to 'temp'
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node* deleteNodeAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return head;
    }

    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head; // Changed 'current' to 'temp'
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head; // Changed 'current' to 'temp'
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int data, choice, position;

    printf("Enter the number of nodes for the linked list: ");
    int numNodes;
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

  do {
        printf("\nLinked List: ");
        display(head);
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at a particular position\n");
        printf("3. Insert at the end\n"); // Added option for inserting at the end
        printf("4. Delete a node at a particular position\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNodeAtPosition(head, position);
                break;
            case 5:
                // Quit the program
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    // Free the memory allocated for the linked list nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
