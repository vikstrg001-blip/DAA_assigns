#include <stdio.h>
#define SIZE 100

int hashSet[SIZE];

void insert(int key) {
    int index = (key % SIZE + SIZE) % SIZE;
    while (hashSet[index] != -1) {
        if (hashSet[index] == key) return;
        index = (index + 1) % SIZE;
    }
    hashSet[index] = key;
}

int search(int key) {
    int index = (key % SIZE + SIZE) % SIZE;
    int start = index;
    while (hashSet[index] != -1) {
        if (hashSet[index] == key) return 1;
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    return 0;
}

int main() {
    int arr[] = {2, 7, 11, 15,14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 29;
    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        hashSet[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (search(complement)) {
            printf("Found pair: %d + %d = %d\n", complement, arr[i], target);
            found = 1;
            break;
        }
        insert(arr[i]);
    }

    if (!found) {
        printf("No pair found\n");
    }

    return 0;
}