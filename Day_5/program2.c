/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 */
#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;          // Last valid element in nums1
    int j = n - 1;          // Last element in nums2
    int k = m + n - 1;      // Last index of nums1

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;

    // Input sizes
    printf("Enter m: ");
    scanf("%d", &m);

    printf("Enter n: ");
    scanf("%d", &n);

    int nums1[m + n];
    int nums2[n];

    // Input nums1 (first m elements)
    printf("Enter %d elements of nums1:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Fill remaining space with 0s
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    // Input nums2
    printf("Enter %d elements of nums2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Merge arrays
    merge(nums1, m, nums2, n);

    // Output merged array
    printf("Merged array:\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
