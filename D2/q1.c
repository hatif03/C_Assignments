#include <stdio.h>
#include <stdlib.h>

// Define Max size with a macro
#define MAX_SIZE 10

// Define a structure called "Stack"
typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

// Write a function called "initialize" to initialize the stack
void initialize(Stack *stack) {
  stack->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
  return stack->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
  return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Stack Overflow: Unable to push element %d\n", value);
    return;
  }
  stack->arr[++stack->top] = value;
  printf("Pushed element: %d\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow: Unable to pop element\n");
    return -9995; // This value indicates an error condition
  }
  return stack->arr[stack->top--];
}

// Function to display the content of the stack
void display(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty.\n");
    return;
  }
  printf("Stack elements: ");
  for (int i = 0; i <= stack->top; ++i) {
    printf("%d ", stack->arr[i]);
  }
  printf("\n");
}

int main() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  int i, choice, value, testCases;
  scanf("%d", &testCases);
  for (i = 0; i < testCases; ++i) {
    printf("#############################\n\t\tTEST CASE "
           "%d\t\n#############################\n",
           i + 1);
    initialize(stack);
    do {
      printf("\nMenu:\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      printf("%d", choice);
      switch (choice) {
      case 1:
        printf("\nEnter the value to push: ");
        scanf("%d", &value);
        push(stack, value);
        display(stack);
        break;
      case 2:
        value = pop(stack);
        if (value != -9995) {
          printf("\nPopped element: %d\n", value);
        }
        display(stack);
        break;
      case 3:
        display(stack);
        break;
      case 4:
        printf("\nExiting the program.\n");
        break;
      default:
        printf("\nInvalid choice. Please enter a valid option.\n");
      }
    } while (choice != 4);
  }
  return 0;
}
