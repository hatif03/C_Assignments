#include <stdio.h>
#include <stdlib.h>

// Define Node structure for the stack
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

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to push element %d\n", value);
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Unable to pop element\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = stack->top;
    int value = temp->data;

    stack->top = temp->next;
    free(temp);

    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    Stack stack;
    initialize(&stack);

    char* token = postfix;
    while (*token != '$') {
        if (*token >= '0' && *token <= '9') {
            push(&stack, *token - '0'); // Convert character to integer
        } else if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (*token) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }

        token++;
    }

    return pop(&stack);
}

int main() {
    char postfix[] = "12,7,3,-,/,2,1,5,+,*,$";
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
