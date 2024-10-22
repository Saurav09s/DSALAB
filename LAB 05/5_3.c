#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

// Structure for the header of the linked list
typedef struct Header {
    int count; // Number of non-zero elements
    Node* next; // Pointer to the first node
} Header;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a header for the sparse matrix
Header* createHeader() {
    Header* header = (Header*)malloc(sizeof(Header));
    header->count = 0;
    header->next = NULL;
    return header;
}

// Function to insert a new node into the sparse matrix
void insert(Header* header, int row, int col, int value) {
    if (value == 0) return; // Do not store zero values

    Node* newNode = createNode(row, col, value);
    newNode->next = header->next;
    header->next = newNode;
    header->count++;
}

// Function to display the sparse matrix
void display(Header* header) {
    printf("Sparse Matrix (row, col, value):\n");
    printf("Total non-zero elements: %d\n", header->count);
    Node* current = header->next;
    while (current != NULL) {
        printf("(%d, %d, %d)\n", current->row, current->col, current->value);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(Header* header) {
    Node* current = header->next;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(header);
}

int main() {
    Header* header = createHeader();
    int rows, cols;

    // User input for dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // User input for the matrix elements
    printf("Enter the elements of the matrix (0 for zero values):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &value);
            insert(header, i, j, value);
        }
    }

    // Display the sparse matrix
    display(header);

    // Free allocated memory
    freeList(header);

    return 0;
}
