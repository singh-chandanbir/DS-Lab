#include <iostream>
using namespace std;
int main()
{
    int size = 0;
    int *arr = new int[size];
    cout << arr << endl;
    // cout << sizeof(arr[])<<endl;
    cin >> size;
    cout << arr << endl;
    cout << sizeof(arr);
    cout<<sizeof(size)<<endl;
    int element;
    for (int i = 0; i < size; i++)
    {

        cin >> element;
        arr[i] = element;
    }
    cout << arr << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    cin >> size;
    cout << sizeof(arr);
    cout << arr << endl;

    for (int i = 0; i < size; i++)
    {

        cin >> element;
        arr[i] = element;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }


  
    return 0;
}