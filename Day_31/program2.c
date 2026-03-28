/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) 
{
    char stack[10000];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        // Push opening brackets
        if(ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else
        {
            // If stack empty
            if(top == -1)
                return false;

            char open = stack[top--];

            if((ch == ')' && open != '(') ||
               (ch == '}' && open != '{') ||
               (ch == ']' && open != '['))
            {
                return false;
            }
        }
    }

    // If stack empty → valid
    if(top == -1)
        return true;
    else
        return false;
}

int main()
{
    char s[10000];

    printf("Enter string: ");
    scanf("%s", s);

    if(isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}