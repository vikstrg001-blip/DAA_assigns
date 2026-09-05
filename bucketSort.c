#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

struct Node {
    int data;
    struct Node* next;
};

void sortedInsert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(int arr[], int n) {
    struct Node* b[BUCKETS] = {NULL};

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    for (int i = 0; i < n; i++) {
        int b_idx = (arr[i] * (BUCKETS - 1)) / max_val;
        sortedInsert(&b[b_idx], arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < BUCKETS; i++) {
        struct Node* temp = b[i];
        while (temp != NULL) {
            arr[idx++] = temp->data;
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}