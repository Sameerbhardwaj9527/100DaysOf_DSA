/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int maxSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;

    int *result = (int*)malloc(sizeof(int) * maxSize);
    int *visited = (int*)calloc(nums2Size, sizeof(int));

    int i, j, k = 0;

    for (i = 0; i < nums1Size; i++)
    {
        for (j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j] && visited[j] == 0)
            {
                result[k++] = nums1[i];
                visited[j] = 1;
                break;
            }
        }
    }

    *returnSize = k;
    free(visited);
    return result;
}

int main()
{
    int nums1[100], nums2[100];
    int n1, n2;
    int i;

    printf("Enter size of nums1: ");
    scanf("%d", &n1);

    printf("Enter elements of nums1:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    printf("Enter size of nums2: ");
    scanf("%d", &n2);

    printf("Enter elements of nums2:\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    int returnSize;
    int *result = intersect(nums1, n1, nums2, n2, &returnSize);

    printf("Intersection: ");
    for (i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    free(result);

    return 0;
}

