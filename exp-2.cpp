#include <iostream>
#include <unistd.h>
using namespace std;

void pushElement()
{
}
void popElement()
{
}
void checkPalindrome()
{
}
void overFlow()
{
}
void underFlow()
{
}
void displayStack(){

};

int main()
{
    for (int i = 0; i < 1;)
    {

        // Displaying the menu
        cout << "a.Push an Element on to Stack" << endl;
        cout << "b.Pop an Element from Stack" << endl;
        cout << "c.Demonstrate how Stack can be used to check Palindrome" << endl;
        cout << "d.Demonstrate Overflow and Underflow situations on Stack" << endl;
        cout << "e.Display the status of Stack" << endl;
        cout << "f.Exit " << endl;
        cout << "\n\n";
        cout << "Enter the corresponding character";

        // charactor to navigate in the menu
        char check;
        cin >> check;

        // condition to navigate in the menu
        switch (check)
        {
        case 'a':

            break;
        case 'b':

            break;
        case 'c':

            break;
        case 'd':

            break;
        case 'e':

            break;
        case 'f':
            cout << "Exiting the program.....\n";
            sleep(2);
            cout << "Bye Bye";
            return 0;

        default:
            cout << "Enter valid character";
            break;
        }
    }

    return 0;
}