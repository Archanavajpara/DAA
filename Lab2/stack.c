// Write a program to implement stack operations (PUSH, POP, PEEP, CHANGE & DISPLAY)
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = x;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}
void peep() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
void change(int pos, int x) {
    if (pos < 1 || pos > top + 1) {
        printf("Invalid position\n");
    } else {
        stack[pos - 1] = x;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, x, pos;
    while (1) {
        printf("1. Push\n2. Pop\n3. Peep\n4. Change\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                printf("Enter position and new value: ");
                scanf("%d %d", &pos, &x);
                change(pos, x);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}