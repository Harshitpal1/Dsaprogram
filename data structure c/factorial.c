#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char stackState[100][100];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, const char* state) {
    if (stack->top < 99) {
        strcpy(stack->stackState[++stack->top], state);
    }
}

void pop(Stack* stack) {
    if (stack->top > -1) {
        stack->top--;
    }
}

void displayStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("\n--- Current Stack State ---\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s\n", stack->stackState[i]);
    }
    printf("---------------------------\n");
}

int factorial(int n, Stack* stack) {
    char state[100];
    sprintf(state, "factorial(%d) - Entering", n);
    push(stack, state);
    displayStack(stack);

    if (n == 0 || n == 1) {
        sprintf(state, "Returning 1 from factorial(%d)", n);
        push(stack, state);
        displayStack(stack);
        pop(stack);
        return 1;
    }

    int result = n * factorial(n - 1, stack);
    sprintf(state, "Returning %d from factorial(%d)", result, n);
    push(stack, state);
    displayStack(stack);
    pop(stack);
    return result;
}

int main() {
    int num;
    Stack stack;

    initStack(&stack);

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    printf("\nCalculating Factorial of %d with Stack Simulation:\n", num);
    int result = factorial(num, &stack);
    printf("\nFactorial of %d is: %d\n", num, result);

    return 0;
}
