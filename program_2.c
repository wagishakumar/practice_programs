#include <stdio.h>

int main() {
    int arr[100], n, i;
    int smallest, position;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is smallest
    smallest = arr[0];
    position = 0;

    // Find smallest element
    for(i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            position = i;
        }
    }

    // Output result
    printf("Smallest number is: %d\n", smallest);
    printf("Position is: %d\n", position + 1);  // +1 for user-friendly position

    return 0;
}
