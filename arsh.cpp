#include <iostream>
using namespace std;
class stack
{
private:
    int size = 0;
    int *arr = new int[size];

    int top = -1;

public:
    stack(int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    void push(int element)
    {
        if (top == size)
        {
            cout << "Overflow Condition" << endl
                 << "More Element Can't Be Added";
        }
        else
        {
            top++;
            arr[top] = element;
        }
        size ++;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Underflow Condition" << endl
                 << "Empty Stack";
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            cout << "Popped Value =" << popvalue;
        }
        size --;
    }
    // void showstack()
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         cout << arr[i];
    //     }
    // }
    void change(int pos, int value)
    {
        arr[pos] = value;
        cout << "The Value Is Changed At " << pos << "Position" << endl;
    }
    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{

    int size;
    cin >> size;
    stack s1(size);
    int value;
    int option;
    int position;
    do
    {
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. change()" << endl;
        cout << "4. display()" << endl;
        cout << "5. Clear Screen" << endl
             << endl;
        cout << "enter the option value";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter element to be pushed : ";
            cin >> value;
            s1.push(value);
            break;

        case 2:
            cout << "Element popped out is : ";
            s1.pop();
            break;

        case 3:
            cout << "Enter position you want to change : ";
            cin >> position;
            cout << "Enter the value : ";
            cin >> value;
            break;

        case 4:
            cout << "The Stack You Have Is : ";
            s1.display();
            break;

        default:
            cout << "error";
        }

    } while (option != 0);

    return 0;
}