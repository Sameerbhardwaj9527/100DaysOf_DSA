/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.
Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.*/
#include <stdio.h>

long long missingNum(int arr[], int size) {
    long long n = size + 1;
    long long expected_sum = n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < size; i++) {
        actual_sum += arr[i];
    }

    return expected_sum - actual_sum;
}
