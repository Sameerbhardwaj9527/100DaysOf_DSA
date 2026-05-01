#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int original_idx;
} Element;

void merge(Element* arr, int* count, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Element* L = (Element*)malloc(n1 * sizeof(Element));
    Element* R = (Element*)malloc(n2 * sizeof(Element));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int right_smaller_count = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            // When taking from Left, add how many from Right were smaller
            count[L[i].original_idx] += right_smaller_count;
            arr[k++] = L[i++];
        } else {
            // When taking from Right, increment the smaller counter
            right_smaller_count++;
            arr[k++] = R[j++];
        }
    }

    // Clean up remaining Left elements
    while (i < n1) {
        count[L[i].original_idx] += right_smaller_count;
        arr[k++] = L[i++];
    }
    // Clean up remaining Right elements
    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Element* arr, int* count, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    Element* arr = (Element*)malloc(n * sizeof(Element));
    int* count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].original_idx = i;
    }

    mergeSort(arr, count, 0, n - 1);

    printf("Count of smaller elements to the right: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(arr);
    free(count);
    return 0;
}