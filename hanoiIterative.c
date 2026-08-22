#include <stdio.h>
#include <math.h>

void moveDisk(char from, char to, int disk) {
    printf("Move %d from %c to %c\n", disk, to);
}

void moveBetween(char src, char dest, int s[], int *topS, int d[], int *topD) {
    if (*topS == -1) {
        s[++(*topS)] = d[(*topD)--];
        printf("Move disk %d from %c to %c\n", s[*topS], dest, src);
    } else if (*topD == -1) {
        d[++(*topD)] = s[(*topS)--];
        printf("Move disk %d from %c to %c\n", d[*topD], src, dest);
    } else if (s[*topS] > d[*topD]) {
        s[++(*topS)] = d[(*topD)--];
        printf("Move disk %d from %c to %c\n", s[*topS], dest, src);
    } else {
        d[++(*topD)] = s[(*topS)--];
        printf("Move disk %d from %c to %c\n", d[*topD], src, dest);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    char src = 'A', dest = 'C', aux = 'B';
    
    if (n % 2 == 0) {
        char temp = dest;
        dest = aux;
        aux = temp;
    }

    int totalMoves = (int)pow(2, n) - 1;
    int srcStack[10], auxStack[10], destStack[10];
    int topSrc = -1, topAux = -1, topDest = -1;

    for (int i = n; i >= 1; i--) {
        srcStack[++topSrc] = i;
    }

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetween(src, dest, srcStack, &topSrc, destStack, &topDest);
        } else if (i % 3 == 2) {
            moveBetween(src, aux, srcStack, &topSrc, auxStack, &topAux);
        } else if (i % 3 == 0) {
            moveBetween(aux, dest, auxStack, &topAux, destStack, &topDest);
        }
    }

    return 0;
}