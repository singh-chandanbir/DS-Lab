#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string usn;
    string name;
    string branch;
    int sem;
    long phno;
    Node *next;

    Node(string usn, string name, string branch, int sem, long phno) {
        this->usn = usn;
        this->name = name;
        this->branch = branch;
        this->sem = sem;
        this->phno = phno;
        this->next = NULL;
    }
};

class SLL {
private:
    Node *head;

public:
    SLL() {
        this->head = NULL;
    }

    void create(int n) {
        for (int i = 0; i < n; i++) {
            string usn, name, branch;
            int sem;
            long phno;
            cout << "Enter USN: ";
            cin >> usn;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter Semester: ";
            cin >> sem;
            cout << "Enter Phone Number: ";
            cin >> phno;
            Node *node = new Node(usn, name, branch, sem, phno);
            node->next = this->head;
            this->head = node;
        }
    }

    void display() {
        if (this->head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node *node = this->head;
        while (node != NULL) {
            cout << "USN: " << node->usn << ", Name: " << node->name << ", Branch: " << node->branch << ", Semester: " << node->sem << ", Phone Number: " << node->phno << endl;
            node = node->next;
        }
    }

    void count() {
        int count = 0;
        Node *node = this->head;
        while (node != NULL) {
            count++;
            node = node->next;
