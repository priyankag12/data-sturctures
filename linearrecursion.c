#include <stdio.h>

int linearSearchRecursive(int arr[], int n, int target, int index) {
    if (index == n) {
        return -1; 
    }
    if (arr[index] == target) {
        return index; 
    }
    return linearSearchRecursive(arr, n, target, index + 1);
}
int main() {
    int n, target;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = linearSearchRecursive(arr, n, target, 0);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    return 0;
}


