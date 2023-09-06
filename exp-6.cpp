#include <iostream>
using namespace std;

class node
{

public:
    string name;
    int urn;
    int sem;
    string branch;
    int phone;

    node *next;

    node(int urn, string name, string branch, int sem, int phno)
    {
        this->urn = urn;
        this->name = name;
        this->branch = branch;
        this->sem = sem;
        this->phone = phno;
        this->next = NULL;
    }

    void create(){

        
    }
};
int main()

{

    int menu = 0;

   
    while (menu != 5)
    {
        cout << " a. Create a SLL of N Students Data by using front insertion.\n b. Display the status of SLL and count the number of nodes in it \n c. Perform Insertion / Deletion at End of SLL \nd. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)\n e.Exit " << endl;
        cin >> menu;

        switch (menu)
        {
        case 1 :
            
            break;
        
        case 2 :
            break;

        case 3 :

            break;

        case 4 :

            break;

        case 5 :

            break;

        default:
            break;
        }
    }


    return 0;
}