#include <iostream>
#include <string>
using namespace std;

char stk[50], top = -1;
void push(char a)
{

    if (top >= 50)
    {
        cout << "stack overflow";
    }
    else
    {
        top++;
        stk[top] = a;
    }
}

void pop()
{
    if (top <= -1)
    {
        cout << "stack under flow";
    }
    else
    {
        top--;
    }
}

int checkPrecedence(char c)

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

int main()

{
    string infix;
    string postfix;
    cout << "Enter the infix string: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            postfix += infix[i];
        }
        else if (infix[i] == ')')
        {
            for (; stk[top] != '(';)
            {
                postfix += stk[top];
                pop();
            };
            pop();
        }
        else if (infix[i] == '+' || '-' || '*' || '/' || '%' || '^')
        {
            if (top == -1)
            {
                push(infix[i]);
            }
            else
            {
                if (checkPrecedence(infix[i]) >= checkPrecedence(stk[top]))
                {
                    push(infix[i]);
                }
                else
                {
                    while (top != -1)
                    {
                        postfix += stk[top];
                        pop();
                    }
                    // push(infix[i]);
                }
            }
        }
    }

    while (top != -1)
    {
        postfix += stk[top];
        pop();
    }
    cout << "Postfix expression is: " << postfix << endl;

    return 0;
}