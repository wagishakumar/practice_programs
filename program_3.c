#include <stdio.h>

int main() {
    int arr[100], n, i, j;
    int duplicateFound = 0;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check for duplicates
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                printf("Duplicate element found: %d\n", arr[i]);
                duplicateFound = 1;
            }
        }
    }

    if(duplicateFound == 0) {
        printf("No duplicate elements found.\n");
    }

    return 0;
}
