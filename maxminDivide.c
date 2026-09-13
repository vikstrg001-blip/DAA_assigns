#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = low + (high - low) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int arr[] = {1000, 121,56,11,566,3000,865,-1,-345};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    struct Pair minmax = getMinMax(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}