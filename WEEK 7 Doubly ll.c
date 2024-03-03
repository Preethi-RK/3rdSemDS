
#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node to the left of the given node
void insertNodeToLeft(struct Node** head, struct Node* targetNode, int value) {
    struct Node* newNode = createNode(value);

    if (targetNode->prev != NULL) {
        targetNode->prev->next = newNode;
        newNode->prev = targetNode->prev;
    } else {
        *head = newNode;
    }

    newNode->next = targetNode;
    targetNode->prev = newNode;
}

// Function to delete a node based on a specific value
void deleteNodeByValue(struct Node** head, int value) {
    struct Node* current = *head;

    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }

    printf("Node with value %d not found in the list.\n", value);
}

// Function to display the contents of the doubly linked list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating a doubly linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    // Displaying the initial list
    printf("The intial linked list:\n");
    displayList(head);

    // Inserting a new node to the left of the second node
    printf("Inserting a new node to the left of 2nd node:\n");
    insertNodeToLeft(&head, head->next, 4);
    displayList(head);

    // Deleting a node with value 2
    int value;
    printf("Enter the value whose corresponding node you want to delete:\n");
    scanf("%d",&value);
    deleteNodeByValue(&head,value);
    displayList(head);

    return 0;
}
