#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void dequeue() {
    if (front == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued : %d\n", front->data);
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}
void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Empty\n");
        return;
    }
    printf("Queue : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();
    enqueue(50);
    display();
    return 0;
}