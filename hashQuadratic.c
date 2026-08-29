#include <stdio.h>
#define SIZE 7

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    while (table[(index + i * i) % SIZE] != -1 && i < SIZE) {
        i++;
    }
    if (i == SIZE) {
        printf("Unable to insert %d\n", key);
    } else {
        table[(index + i * i) % SIZE] = key;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1) {
            printf("[%d] -> %d\n", i, table[i]);
        } else {
            printf("[%d] -> Empty\n", i);
        }
    }
}

int main() {
    init();
    insert(43);
    insert(11);
    insert(24);
    insert(15);
    display();
    return 0;
}