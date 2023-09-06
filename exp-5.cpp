#include <iostream>
using namespace std;


// Circular Queue Class
class CircularQueue {
private:
    int N;
    char* queue=NULL;
    int front, rear;

public:
    CircularQueue() {
        front = 0;
        rear = 0;
        cout<<"Enter the size of the queue:";
        cin>>N;
        queue=new char[N];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Insert an element into the circular queue
    void enqueue(char c) {
        if ((front == 1 && rear == N) || (front == rear+1)) {
            cout << "Overflow condition!\n";
            return;
        }

        if (front == 0) {     //Queue initially empty
            front = 1;
            rear = 1;
        }
        else if (rear == N)
            rear = 1;
        else
            rear++;

        queue[rear] = c;    //Inserts element in queue
    }

    // Delete an element from the circular queue
    char dequeue() {
        if (front == 0) {    //Queue already empty
            cout << "Underflow condition!\n";
            return '\0';
        }

        char element = queue[front];
        if (front == rear) {  //Queue has only one element
            front = 0;
            rear = 0;
        }
        else if (front == N)
            front = 1;
        else
            front++;

        return element;
    }


    // Demonstrate Overflow and Underflow situations on Circular QUEUE
    void display_situation(){
        if ((front == 1 && rear == N) || (front == rear+1)) {
            cout << "Overflow condition!\n";
            
        }
        if (front == 0) {    //Queue already empty
            cout << "Underflow condition!\n";
            
        }
        else{
            cout<<"Queue has space to enter elements!\n";
        }
    }

    // Display the status of the circular queue
    void display_status() {
        if (front == 0) {
            cout << "Circular Queue is empty!\n";
            return;
        }

        cout << "Circular Queue is: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        }
        else {
            for (int i = front; i <= N; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }
};

// Main Function
int main() {
    CircularQueue cq;
    int choice;
    char element;

    do {
        cout << "\nMENU\n";
        cout << "1. Insert an Element on to Circular QUEUE\n";
        cout << "2. Delete an Element from Circular QUEUE\n";
        cout << "3. Demonstrate Overflow and Underflow situations on Circular QUEUE\n";
        cout << "4. Display the status of Circular QUEUE\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                cq.enqueue(element);
                break;

            case 2:
                element = cq.dequeue();
                if (element != '\0')
                    cout << "Deleted Element: " << element << endl;
                break;

            case 3:
                cq.display_situation();
                break;

            case 4:
                cq.display_status();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}