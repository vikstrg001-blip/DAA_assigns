#include <stdio.h>

void hanoiRecursion(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move 1 from %c to %c\n", from, to);
        return;
    }
    hanoiRecursion(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoiRecursion(n - 1, aux, to, from);
}

int main() {
    int n;
    scanf("%d",&n);
    hanoiRecursion(n, 'A', 'C', 'B');
    return 0;
}