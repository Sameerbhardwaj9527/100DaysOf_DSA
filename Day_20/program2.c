/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = 256;
    int **result = (int **)malloc(sizeof(int *) * capacity);
    *returnColumnSizes = (int *)malloc(sizeof(int) * capacity);

    *returnSize = 0;

    for(int i = 0; i < numsSize - 2; i++) {

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {

                if(*returnSize == capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];

                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if(sum < 0) left++;
            else right--;
        }
    }

    return result;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int *returnColumnSizes;

    int **ans = threeSum(nums, n, &returnSize, &returnColumnSizes);

    printf("\nTriplets with sum 0:\n");
    printf("[\n");
    for(int i = 0; i < returnSize; i++) {
        printf("  [%d, %d, %d]\n", ans[i][0], ans[i][1], ans[i][2]);
        free(ans[i]);
    }
    printf("]\n");

    free(ans);
    free(returnColumnSizes);
    free(nums);

    return 0;
}