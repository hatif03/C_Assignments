#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Define Stack structure
typedef struct {
  Node* top;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
  stack->top = NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed. Unable to push element %d\n", value);
    return;
  }

  newNode->data = value;
  newNode->next = stack->top;
  stack->top = newNode;

  printf("Pushed element: %d\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
  if (stack->top == NULL) {
    printf("Stack Underflow: Unable to pop element\n");
    return -9995; // This value indicates an error condition
  }

  Node* temp = stack->top;
  int value = temp->data;

  stack->top = temp->next;
  free(temp);

  return value;
}

// Function to display the content of the stack
void display(Stack* stack) {
  if (stack->top == NULL) {
    printf("Stack is empty.\n");
    return;
  }

  printf("Stack elements: ");
  Node* current = stack->top;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Function to free the dynamically allocated memory
void cleanup(Stack* stack) {
  Node* current = stack->top;
  while (current != NULL) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
}

int main() {
  Stack stack;
  int i, choice, value, testCases;

  scanf("%d", &testCases);
  for (i = 0; i < testCases; ++i) {
    printf("#############################\n\t\tTEST CASE %d\t\n#############################\n", i + 1);

    initialize(&stack);

    do {
      printf("\nMenu:\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
        printf("\nEnter the value to push: ");
        scanf("%d", &value);
        push(&stack, value);
        display(&stack);
        break;
      case 2:
        value = pop(&stack);
        if (value != -9995) {
          printf("\nPopped element: %d\n", value);
        }
        display(&stack);
        break;
      case 3:
        display(&stack);
        break;
      case 4:
        printf("\nExiting the program.\n");
        break;
      default:
        printf("\nInvalid choice. Please enter a valid option.\n");
      }
    } while (choice != 4);

    // Free the dynamically allocated memory
    cleanup(&stack);
  }

  return 0;
}
