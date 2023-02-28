#include <iostream>
#include <unistd.h>
#include <stack>
using namespace std;
class myStack
{
private:
    int size = 0;
    int *arry = new int[size];
    int top = -1;

public:
    myStack(int size)
    {
        this->size = size;
    }
    void pushElement(int a)
    {
        if (top >= size - 1)
        {
            cout << "\tSTACK OVERFLOW\n"
                 << endl
                 << "more elements can't me added" << endl;
        }
        else if (-1 <= top < size - 1)
        {
            top++;
            arry[top] = a;
        }
    };
    void popElement()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "\n stack under flow";
        }
    };
    void checkPalindrome(){};
    void overFlow(){};
    void underFlow(){};
    void displayStatus(){

    };
};

int main()
{
    char check;
    int element, size;
    // stack (object) creation and size selection

    cout << "Enter the size of stack" << endl;
    cin >> size;
    myStack stk(size);

    do
    {
        // Displaying the menu
        cout << "\n\t\tMENU\n";

        cout << "a.Push an Element on to Stack" << endl;
        cout << "b.Pop an Element from Stack" << endl;
        cout << "c.Demonstrate how Stack can be used to check Palindrome" << endl;
        cout << "d.Demonstrate Overflow and Underflow situations on Stack and Display the status of Stack" << endl;
        cout << "e.Exit" << endl;
        cout << "\n";
        cout << "Enter the corresponding character" << endl;

        // charactor to navigate in the menu
        cin >> check;

        // condition to navigate in the menu
        switch (check)
        {
        case 'a':
            cout << "Enter the element to be pushed" << endl;
            cin >> element;
            stk.pushElement(element);

            break;
        case 'c':

            break;
        case 'd':

            break;

        case 'e':
            cout << "Exiting the program.....\n"
                 << endl;
            sleep(2);
            cout << "Bye Bye";
            return 0;

        default:
            cout << "Enter valid character" << endl;
            break;
        }

        system("read");
    } while (check != 'e');

    return 0;
}