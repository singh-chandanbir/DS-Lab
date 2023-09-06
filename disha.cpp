#include <iostream>
#include <cstring>
int stack[30], i, top = -1;
using namespace std;
int prec(char c)

{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void push(char c)
{
    if (top == 29)
    {
        cout << "Overflow\n";
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        top--;
    }
}
int main()
{
    string str;
    string res;
    cout << "Enter expression:\n";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                res += stack[top];
                pop();
            }
            if (top != -1)
            {
                pop();
            }
        }

        else
        {
            while (top != -1 && prec(stack[top]) > prec(str[i]))
            {
                res += stack[top];
                pop();
            }
            push(str[i]);
        }
    }
    while (top != -1)
    {
        res += stack[top];
        pop();
    }
    cout << "\nPostfix expression is: " << res;
}