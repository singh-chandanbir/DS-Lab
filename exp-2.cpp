#include <iostream>
#include <unistd.h>

using namespace std;
class myStack
{
private:
    // creating a array
    int size = 0;
    int *arry = new int[size];
    int top = -1;

public:
    // using constuctor to set the size of stack
    myStack(int size)
    {
        this->size = size;
    }

    // funtion to push element
    void pushElement()
    { // element that is to be pushed
        int element;
        cout << "Enter the element to be pushed" << endl;
        cin >> element;
        if (top >= size - 1)
        {
            cout << "\tSTACK OVERFLOW\n"
                 << endl
                 << "more elements can't me added" << endl;
        }
        else if (top < size - 1)
        {
            top++;
            arry[top] = element;
            cout << element << " pushed" << endl;
        }
    };
    void pushElement(int b)
    {
        int element;
        cout << "Enter the element to be pushed" << endl;
        element = b;
        if (top >= size - 1)
        {
            cout << "\tSTACK OVERFLOW\n"
                 << endl
                 << "more elements can't me added" << endl;
        }
        else if (top < size - 1)
        {
            top++;
            arry[top] = element;
            cout << element << " pushed to stack" << endl;
        }
    };

    void popElement()
    {
        if (top > -1)
        {
            top--;
            cout << "last element poped" << endl;
        }
        else
        {
            cout << "\n stack under flow";
        }
    };
    void checkPalindrome()
    {
        string str;
        cout << "Enter a string to check palindrome: ";
        cin >> str;

        int len = str.length();
        int mid = len / 2;
        bool is_palindrome = true;

        for (int i = 0; i < mid; i++)
        {
            pushElement(str[i]); // push first half of string onto stack
        }

        // compare second half of string with top elements of stack
        if (len % 2 == 1)
        {
            mid++; // skip middle character if odd length
        }
        for (int i = mid; i < len; i++)
        {
            if (str[i] != arry[top])
            {
                is_palindrome = false;
                break;
            }
            else
            {
                popElement();
            }
        }

        if (is_palindrome)
        {
            cout << str << " is a palindrome.\n";
        }
        else
        {
            cout << str << " is not a palindrome.\n";
        }
    }

    void displayStatus()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arry[i] << " ";
        }
        cout << "\nStack Size: " << top + 1 << "\n";
    };
};

int main()
{
    system("clear");
    char menu;
    int element, size;

    // stack (object) creation with size selection
    cout << "Enter the size of stack" << endl;
    cin >> size;
    myStack stk(size);

    do
    {
        system("clear");
        // Displaying the menu
        cout << "\n\t\tMENU\n";
        cout << "a.Push an Element on to Stack" << endl;
        cout << "b.Pop an Element from Stack" << endl;
        cout << "c.Demonstra4te how Stack can be used to check Palindrome" << endl;
        cout << "d.Demonstrate Overflow and Underflow situations on Stack and Display the status of Stack" << endl;
        cout << "e.Exit" << endl;
        cout << "\n";
        cout << "Enter the corresponding character" << endl;

        // charactor to navigate in the menu
        cin >> menu;

        // condition to navigate in the menu
        switch (menu)
        {
        case 'a':
            stk.pushElement();
            break;
        case 'b':
            stk.popElement();
            break;
        case 'c':
            stk.checkPalindrome();
            break;
        case 'd':
            stk.displayStatus();
            break;

        case 'e':
            cout << "Exiting the program....."
                 << endl;
            sleep(2);
            cout << "Bye Bye";
            return 0;

        default:
            cout << "Enter valid character" << endl;
            break;
        }
        cout << "\tPress enter to continue....." << endl;
        system("read");
    } while (menu != 'e');
    system("clear");

    return 0;
}