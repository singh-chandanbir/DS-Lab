#include <iostream>
using namespace std;
class node
{

public:
    int coff;
    char variable;
    int power;

    node *next;

    node()
    {
        cout << "\nEnter the variable s(x,y,z) {if is a constant enter 0}:";
        cin >> this->variable;

        cout << "\nEnter power:" << variable << "^__   {if is a constant enter 0}";
        cin >> this->power;

        cout << "\nEnter coff or the constant:"
             << "__" << variable << "^" << power;
        cin >> this->coff;
    }
    node(int coff, int variable, int power)
    {
        this->coff = coff;
        this->power = power;
        this->variable = variable;
    }
};
void insertNode(node *&head, node *&ref)
{
    node *temp = new node();

    ref->next = temp;
    ref = temp;
    temp->next = head;
}
void insertNode(node *&head, int coff, int variable, int power)
{
    if (head == NULL)
    {
        node *newList = new node(coff, variable, power);
        head = newList;
        newList->next = head;
    }
    else
    {
        node *temp = new node(coff, variable, power);

        // head = temp;

        node *tempRef = head;
        if (head->next == head)
        {
            tempRef->next = temp;
            temp->next = head;
        }
        else
        {
            do
            {
                tempRef = tempRef->next;
            } while (tempRef != head);

            tempRef->next = temp;
            temp->next = head;
        }
    }
}
void builtcircularList(node *&head)
{
    cout << "Enter the number of terms in your polynomial" << endl;
    int count;
    cin >> count;
    node *temp = new node();
    head = temp;

    temp->next = head;

    node *ref = head;
    for (int i = 1; i < count; i++)
    {
        insertNode(head, ref);
    }
}

void print(node *head)
{
    node *temp = head;

    do
    {
        if (temp->variable == 0)
        {
            cout << temp->coff;
        }
        else
        {
            cout << temp->coff << temp->variable << "^" << temp->power << " + ";
            
        }
        temp = temp->next;

    } while (temp != head);

    cout << endl;
}
node *add(node *&head1, node *&head2)
{
    node *ref1 = head1;
    node *ref2 = head2;
    int tempSum;
    node *sum = NULL;

    do
    {
        do
        {
            if ((ref1->power == ref2->power) && (ref1->variable == ref2->variable))
            {
                tempSum = ref1->coff + ref2->coff;
                insertNode(sum, tempSum, ref1->variable, ref1->power);
                ref1->coff = INT_MIN;
                ref2->coff = INT_MIN;

                ref1->power = INT_MIN;
                ref2->power = INT_MIN;
            }
            else
            {
                insertNode(sum, ref1->coff, ref1->variable, ref1->power);
            }
            ref2 = ref2->next;

        } while (ref2->next != head2);
        ref1 = ref1->next;

    } while (ref1->next != head1);

    do
    {
        if ((ref2->coff != INT_MIN) && (ref2->power != INT_MIN))
        {
            insertNode(sum, ref2->coff, ref2->variable, ref2->power);
        }
        ref2 = ref2->next;
    } while (ref2 != head2);

    // if ((ref1->variable == ref2->variable) && (ref1->power == ref2->power))
    // {
    //     tempSum = ref1->coff + ref2->coff;
    // }
    // node *sum = new node(tempSum, ref1->variable, ref1->power);
    // node *refSum = sum;
    // refSum = sum->next;
    // int count = 0;

    // for (; ref1 != head1; ref1 = ref1->next)
    // {
    //     for (; ref2 != head2; ref2 = ref2->next)
    //     {
    //         if ((ref1->variable == ref2->variable) && (ref1->power == ref2->power))
    //         {
    //             tempSum = ref1->coff + ref2->coff;
    //             insertNode(sum, tempSum, ref1->variable, ref1->power);
    //         }
    //         if (ref2 == head2)
    //         {
    //             break;
    //         }
    //     }
    //     if (ref1 == head1)
    //     {
    //         break;
    //     }
    // }

    // do
    // {
    //     do
    //     {
    //         ref2->next
    //     } while (ref2->next);

    // } while (/* condition */);

    return sum;
}

int main()

{

    node *head1 = NULL;
    node *head2 = NULL;

    cout << "Enter the detailes of First Polynomial;" << endl;
    builtcircularList(head1);
    cout << "Enter the detailes of Second Polynomial;" << endl;
    builtcircularList(head2);

    cout << "Your entered polynomials are :" << endl;
    print(head1);
    print(head2);

    cout << "\nSum of the above polynomials is :" << endl;
    node *sum = add(head1, head2);
    print(sum);

    return 0;
}



//   5x22y24x12y12001   5x31y32x11y13000

//   5x31y32x11y13000
