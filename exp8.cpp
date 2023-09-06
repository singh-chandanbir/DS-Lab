#include <iostream>
using namespace std;

class node
{

public:
    int coff;
    int degree;
    node *next;
    node(int degree, int coff)
    {
        this->degree = degree;
        this->coff = coff;
    }
};
void insertNode(node *head, int degree, node *&ref, int coff)
{
    node *temp = new node(degree, coff);

    ref->next = temp;
    ref = temp;
    temp->next = head;
}

void creatPolynomial(node *&head)
{
    cout << "Enter the coff of X^2:" << endl;
    int coff;
    cin >> coff;
    node *poly = new node(2, coff);
    head = poly;
    poly->next = head;

    node *ref = head;
    cout << "enter the coff of x:" << endl;
    cin >> coff;
    insertNode(head, 1, ref, coff);
    cout << "enter the constant:" << endl;
    cin >> coff;
    insertNode(head, 0, ref, coff);
}

void print(node *&head)
{
    node *ref = head;
    do
    {
        if (ref->degree == 0)
        {
            cout << ref->coff << endl;
        }
        else
        {
            cout << ref->coff << "x^" << ref->degree << " + ";
        }

        ref = ref->next;
    } while (ref != head);
}

node *sumPlynomial(node *poly1, node *poly2)
{
    node *ref1 = poly1;
    node *ref2 = poly2;

    int tempSum = poly1->coff + poly2->coff;
    node *sum = new node(2, tempSum);
    node *ref = sum;

    for (int i = 1; i >= 0; i--)
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
    cout <<"Enter the detailes of First Polynomial;"<<endl;
    creatPolynomial(polynomial1);
    cout <<"Enter the detailes of Second Polynomial;"<<endl;
    creatPolynomial(polynomial2);
    cout<<"Your entered polynomials are :"<<endl;
    print(polynomial1);
    print(polynomial2);
    node *sum = sumPlynomial(polynomial1, polynomial2);


    cout<< "\nSum of the above polynomials is :"<<endl;
    print (sum);

    return 0;
}