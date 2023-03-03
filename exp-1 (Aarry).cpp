#include <iostream>
#include <array>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

class arrayfuntion
{
private:
    int size = 0;
    int *arr = new int[size];

public:
    void setdata(int a)
    {
        size = a;
        int temp;
        cout << "Enter the value in array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "]= ";
            cin >> temp;
            arr[i] = temp;
        }
    }
    void displaydata()
    {
        cout << "Your array is: \n";
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "]=" << arr[i] << endl;
        }
        cout << "Press enter to return to menu...." << endl;
    }
    void insertElement(int a, int b)
    {
        for (int i = size; i >= a; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[a] = b;
        size++;
    }
    void deleteElement(int a)
    {
        for (int i = a; i <= size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};
int main()
{
    arrayfuntion obj;
    int menu, length, index, val;

    for (int i = 0; i == 0;)
    {
        system("clear");
        cout << "Enter te corresponting integer\n";
        cout << "  1. Creating a array of n integer element\n";
        cout << "  2. Display off array element with suitable headings\n";
        cout << "  3. Inserting a element at a given Valid position\n";
        cout << "  4. Deleting an element at a  given valid position\n";
        cout << "  5. Exit\n";
        cin >> menu;
        switch (menu)
        {
        case 1:
            system("clear");
            cout << "1. Creating a array of n integer element \n";
            cout << "Enter the length of array: ";
            cin >> length;
            obj.setdata(length);
            break;
        case 2:
            system("clear");
            obj.displaydata();
            system("read");
            break;
        case 3:
            system("clear");
            cout << "3. Inserting a element at a given Valid position\n";
            cout << "Enter the index at which element is to be inserted: ";
            cin >> index;
            cout << "Enter the value to be inserted: ";
            cin >> val;
            obj.insertElement(index, val);
            break;
        case 4:
            system("clear");
            cout << "4. Deleting an element at a  given valid position\n";
            cout << "Enter the index at which element is to be deleted: ";
            cin >> index;
            obj.deleteElement(index);
            break;
        case 5:
            cout << "Exiting the program.....\n";
            sleep(3);
            cout << "Bye Bye";
            return 0;
        default:
            cout << "Enter a valid correponding integer" << endl;
            break;
        }
    }
    system("CLS");
}