#include <stdio.h>
#define SIZE 100
int keys[SIZE];
int freq[SIZE];
void insert(int key) {
    int index = (key % SIZE + SIZE) % SIZE;
    while (keys[index] != -1) {
        if (keys[index] == key) {
            freq[index]++;
            return;
        }
        index = (index + 1) % SIZE;
    }
    keys[index] = key;
    freq[index] = 1;
}
int main() {
    int arr[] = {3, 2, 5, 3, 3,6,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < SIZE; i++) {
        keys[i] = -1;
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    for (int i = 0; i < SIZE; i++) {
        if (keys[i] != -1) {
            printf("%d occurs %d times\n", keys[i], freq[i]);
        }
    }
    return 0;
}