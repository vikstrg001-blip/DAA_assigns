#include <stdio.h>
int n, s;
void sort(int a[], int n1) {
    for (int i = 0; i < n1 - 1; i++) {
        for (int j = 0; j < n1 - i - 1; j++) {
            if (a[j] > a[j + 1]) { 
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main() {
    printf("Enter Array size ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
}
    printf("\nEnter key to search ");
    scanf("%d", &s);
    sort(a, n);
    printf("Sorted array ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    int l = 0, h = n - 1, f = 0; 
    while (l <= h) { 
        int m = (l + h) / 2;
        if (a[m] > s) {
            h = m - 1;
        } else if (a[m] < s) {
            l = m + 1;
        } else {
            f = m+1;
            break;
        }
    } 
    if (f != 0) {
        printf("\nKey found at  %d", f);
    } else {
        printf("Key not found\n");
    }
    return 0;
}

