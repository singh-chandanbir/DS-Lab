#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
    char arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char val) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack overflow!" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow!" << endl;
            return '\0';
        } else {
            char val = arr[top];
            top--;
            return val;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return '\0';
        } else {
            return arr[top];
        }
    }
};

bool isPalindrome(string str) {
    Stack s;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (s.pop() != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string str = "racecar";

    if (isPalindrome(str)) {
        cout << str << " is a palindrome!" << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
