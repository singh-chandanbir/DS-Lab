#include <iostream>
using namespace std;

class node
{

public:
    int coff;
    char var;
    node *next;
    node(char var, int coff)
    {
        this->var = var;
        this->coff = coff;
    }
};
void insertNode(node *head, char var, node *&ref, int coff)
{
    node *temp = new node(var, coff);

    ref->next = temp;
    ref = temp;
    temp->next = head;
}

void creatPolynomial(node *&head)
{
    cout << "Enter the coff of x:" << endl;
    int coff;
    cin >> coff;
    node *poly = new node('x', coff);
    head = poly;
    poly->next = head;

    node *ref = head;
    cout << "enter the coff of y:" << endl;
    cin >> coff;
    insertNode(head, 'y', ref, coff);
    cout << "enter the coff of z:" << endl;
    cin >> coff;
    insertNode(head, 'z', ref, coff);
}

void print(node *&head)
{
    node *ref = head;
    do
    {
        if (ref->var == 'x' || ref->var == 'y')
        {
            cout << ref->coff<<ref->var << " + ";
        }
        else
        {
            cout << ref->coff<<ref->var<<endl;
        }

        ref = ref->next;

        // else
        // {
        //     cout << ref->coff << "x^" << ref->var << " + ";
        // }

        // ref = ref->next;
    } while (ref != head);
}

node *sumPlynomial(node *poly1, node *poly2)
{
    node *ref1 = poly1;
    node *ref2 = poly2;

    int tempSum = poly1->coff + poly2->coff;
    node *sum = new node('x', tempSum);
    node *ref = sum;

    for (char i = 'x'; i <= 'z'; i++)
    {
        ref1 = ref1->next;
        ref2 = ref2->next;

        tempSum = ref1->coff + ref2->coff;

        insertNode(sum, i, ref, tempSum);
    }

    return sum;
}

int main()
{
    node *polynomial1 = NULL;

    node *polynomial2 = NULL;
    cout << "Enter the detailes of First Polynomial;" << endl;
    creatPolynomial(polynomial1);
    cout << "Enter the detailes of Second Polynomial;" << endl;
    creatPolynomial(polynomial2);
    cout << "Your entered polynomials are :" << endl;
    print(polynomial1);
    print(polynomial2);
    node *sum = sumPlynomial(polynomial1, polynomial2);

    cout << "\nSum of the above polynomials is :" << endl;
    print(sum);

    return 0;
}