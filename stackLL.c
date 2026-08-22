#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (top == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Pop : %d\n", top->data);
    top = top->next;
    free(temp);
}
void peek() {
    if (top == NULL) {
        printf("Empty\n");
    } else {
        printf("Top : %d\n", top->data);
    }
}
void display() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Empty\n");
        return;
    }
    printf("Stack:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    push(67);
    push(10);
    push(28);
    display();
    peek();
    pop();
    display();
    return 0;
}