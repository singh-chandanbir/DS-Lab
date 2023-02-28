#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Stack
{
private:
    int capacity;
    int top_index;
    stack<int> data;

public:
    Stack(int cap)
    {
        capacity = cap;
        top_index = -1;
    }

    void push()
    {
        if (top_index == capacity - 1)
        {
            cout << "\nSTACK OVERFLOW\n"
                 << "Cannot push an element now\n"
                 << "Please pop an element first\n";
            return;
        }
        else
        {

            int element;
            cout << "Enter an element: ";
            cin >> element;
            top_index++;
            data.push(element);
            cout << element << " has been pushed to the stack.\n";
        }
    }

    void
    pop()
    {
        if (top_index == -1)
        {
            cout << "\nSTACK UNDERFLOW\n"
                 << "Cannot pop an element now\n"
                 << "Please push an element first\n";
            return;
        }

        int element = data.top();
        top_index--;
        data.pop();
        cout << element << " has been popped from the stack.\n";
    }

    bool isPalindrome(string str)
    {
        stack<char> s;
        for (char c : str)
        {
            s.push(c);
        }

        for (char c : str)
        {
            if (s.top() != c)
            {
                return false;
            }
            s.pop();
        }
        return true;
    }

    void displayStatus()
    {
        if (top_index == capacity - 1)
        {
            cout << "\nStack is full.\n";
        }
        else if (top_index == -1)
        {
            cout << "\nStack is fully empty.\n";
        }
        else
        {
            cout << "\nStack can contain " << capacity - top_index - 1 << " more elements.\n";
        }
    }
};

int main()
{
    int capacity;
    char option = ' ';
    cout << "Enter the maximum capacity of the stack: ";
    cin >> capacity;
    Stack stack(capacity);

    do
    {
        cout << "\n\t\tMENU\n"
             << "a) Push an element\n"
             << "b) Pop an element\n"
             << "c) Check for palindrome\n"
             << "d) Display stack status\n"
             << "e) Exit\n"
             << "Enter an option from the above: ";
        cin >> option;

        switch (option)
        {
        case 'a':
            stack.push();
            break;

        case 'b':
            stack.pop();
            break;

        case 'c':
        {
            string str;
            cout << "Enter a string: ";
            cin.ignore();
            getline(cin, str);
            if (stack.isPalindrome(str))
            {
                cout << "\n"
                     << str << " is a palindrome.\n";
            }
            else
            {
                cout << "\n"
                     << str << " is not a palindrome.\n";
            }
            break;
        }

        case 'd':
            stack.displayStatus();
            break;

        case 'e':
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid option.\n";
            break;
        }
    } while (option != 'e');

    return 0;
}