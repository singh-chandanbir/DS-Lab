#include <iostream>
using namespace std;

class Employee
{
public:
    int ssn;
    string name;
    string dept;
    string designation;
    int sal;
    string phno;
};

class Node
{
public:
    Employee employee;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void createList(int n)
    {
        Employee emp;
        Node *newNode = nullptr;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter details of employee " << i + 1 << endl;
            cout << "SSN: ";
            cin >> emp.ssn;
            cout << "Name: ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Department: ";
            getline(cin, emp.dept);
            cout << "Designation: ";
            getline(cin, emp.designation);
            cout << "Salary: ";
            cin >> emp.sal;
            cout << "Phone Number: ";
            cin.ignore();
            getline(cin, emp.phno);
            newNode = new Node();
            newNode->employee = emp;
            newNode->prev = tail;
            newNode->next = nullptr;
            if (tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    void displayList()
    {
        Node *current = head;
        int count = 0;
        if (head == nullptr)
        {
            cout << "List is empty! no emmploy to remove" << endl;
        }
        else
        {
            cout << "Employees in the list: " << endl;
            while (current != nullptr)
            {
                cout << "SSN: " << current->employee.ssn << endl;
                cout << "Name: " << current->employee.name << endl;
                cout << "Department: " << current->employee.dept << endl;
                cout << "Designation: " << current->employee.designation << endl;
                cout << "Salary: " << current->employee.sal << endl;
                cout << "Phone Number: " << current->employee.phno << endl;
                count++;
                current = current->next;
            }
        }
        cout << "Total number of employees: " << count << endl;
    }

    void insertAtEnd()
    {
        Employee emp;
        Node *newNode = nullptr;
        cout << "Enter details of the new employee: " << endl;
        cout << "SSN: ";
        cin >> emp.ssn;
        cout << "Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Department: ";
        getline(cin, emp.dept);
        cout << "Designation: ";
        getline(cin, emp.designation);
        cout << "Salary: ";
        cin >> emp.sal;
        cout << "Phone Number: ";
        cin.ignore();
        getline(cin, emp.phno);
        newNode = new Node();
        newNode->employee = emp;
        newNode->prev = tail;
        newNode->next = nullptr;
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Employee added to the end of the list!" << endl;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty! No employee to delete." << endl;
        }
        else if (head->next == nullptr)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            cout << "Employee deleted from the end of the list!" << endl;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            cout << "Employee deleted from the end of the list!" << endl;
        }
    }

    void insertAtFront()
    {
        Employee emp;
        Node *newNode = nullptr;
        cout << "Enter details of the new employee: " << endl;
        cout << "SSN: ";
        cin >> emp.ssn;
        cout << "Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Department: ";
        getline(cin, emp.dept);
        cout << "Designation: ";
        getline(cin, emp.designation);
        cout << "Salary: ";
        cin >> emp.sal;
        cout << "Phone Number: ";
        cin.ignore();
        getline(cin, emp.phno);
        newNode = new Node();
        newNode->employee = emp;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
        cout << "Employee added to the front of the list!" << endl;
    }

    void deleteAtFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty!." << endl;
        }
        else if (head->next == nullptr)
        {
            Node *temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            cout << "Employee deleted from the front of the list!" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            cout << "Employee deleted from the front of the list!" << endl;
        }
    }

    void useAsDeque()
    {
        char choice;
        do
        {
            cout << "Choose an operation to perform on the Deque:" << endl;
            cout << "1. Insert at front" << endl;
            cout << "2. Insert at end" << endl;
            cout << "3. Delete from front" << endl;
            cout << "4. Delete from end" << endl;
            cout << "5. Display Deque" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                insertAtFront();
                break;
            case '2':
                insertAtEnd();
                break;
            case '3':
                deleteAtFront();
                break;
            case '4':
                deleteAtEnd();
                break;
            case '5':
                displayList();
                break;
            case '6':
                cout << "Exiting Deque..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != '6');
    }
};

int main()
{
    DoublyLinkedList dll;
    char choice;
    int n;
    do
    {
        cout << "Choose an operation to perform on the Doubly Linked List:" << endl;
        cout << "1. Create a list" << endl;
        cout << "2. Display the list" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Insert at front" << endl;
        cout << "6. Delete from front" << endl;
        cout << "7. Use as Double Ended Queue" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Enter the number of employees to add: ";
            cin >> n;
            dll.createList(n);
            break;
        case '2':
            dll.displayList();
            break;
        case '3':
            dll.insertAtEnd();
            break;
        case '4':
            dll.deleteAtEnd();
            break;
        case '5':
            dll.insertAtFront();
            break;
        case '6':
            dll.deleteAtFront();
            break;
        case '7':
            dll.useAsDeque();
            break;
        case '8':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '8');
    return 0;
}