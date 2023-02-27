#include <iostream>
#include<array> 

using namespace std;

class arrayfuntion
{
private:
    int n = 0;
    int *arr = new int[n];
   
public:
    void setdata(int a)
    {
        n = a;
        int temp;
        cout << "Enter the value in array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            arr[i] = temp;
        }
    }
    void displaydata()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "arr[" << i << "]=" << arr[i] << endl;
        }
        cout << "Press enter to continue...." << endl;
    }
    void insertElement(int a, int b)
    {
  
        for (int i = n; i >= a; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[a]=b;
        n++;
        
    }
    void deleteElement(int a){
         for (int i = a; i <=n; i++)
        {
            arr[i]=arr[i+1];
        }
        n--;

    }
};
int main()
{
    arrayfuntion obj;
    int menu, length, index, val;

    for (int i = 0; i == 0;)
    {
        cout << "Enter te corresponting integer\n";
        cout << "  1. Creating a array of n integer element\n";
        cout << "  2. Display off array element with suitable headings\n";
        cout << "  3. Inserting a element at a given Vaid position\n";
        cout << "  4. Deleting an element at a  given valid position\n";
        cout << "  5. Exit\n";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Enter the length of array" << endl;
            cin >> length;
            obj.setdata(length);
            break;
        case 2:
            obj.displaydata();
            system("read");
            break;
        case 3:
            cout << "Enter the index at which element is to be inserted: ";
            cin >> index;
            cout << "Enter the val";
            cin >> val;
            obj.insertElement(index, val);
            break;
        case 4:
            cout << "enter the index at which element is to be deleted: ";
            cin >> index;
            obj.deleteElement(index);
            break;
        case 5:
            cout << "bye bye";
            return 0;
        default:
            cout << "Enter a valid correponding integer";
            break;
        }
    }
    system("CLS");
}