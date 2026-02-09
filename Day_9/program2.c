/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.*/
#include <stdio.h>

void reverseString(char* s, int sSize)
{
    int i = 0, j = sSize - 1;
    char temp;

    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char s[100005];
    scanf("%s", s);

    int len = 0;
    while (s[len] != '\0') len++;

    reverseString(s, len);

    printf("%s", s);
    return 0;
}
