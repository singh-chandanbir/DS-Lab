#include <iostream>
using namespace std;

struct node
{
public:
    // DATA
    int number;
    string name;

    // NEXT POINTER
    int *next;

    node(int a , string b)
    {

        number = a;
        name = b;
    }
};
int main()
{   int laptop;
    string name;

    node *head = NULL;
    node obj( laptop , name );

    return 0;
}