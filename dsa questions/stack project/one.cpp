#include <iostream>
using namespace std;

class stack {
private:
    int *arr;
    int top;
    int capacity;

public:

    stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push() {
        int value;
        if (top == capacity - 1) {
            cout << "stack overflow";
            return;
        }
        cout << "enter value: ";
        cin >> value;
        top++;
        arr[top] = value;
        cout << "pushed successfully";
    }

    void pop() {
        if (top == -1) {
            cout << "stack underflow";
            return;
        }
        cout << "popped value: " << arr[top];
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "stack is empty";
            return;
        }
        cout << "top element: " << arr[top];
    }

    void display() {
        if (top == -1) {
            cout << "stack is empty"<<endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
    void isfull(){
       if (top == capacity - 1) {
            cout << "stack is full";
            return;
        }else{
            cout << "stack is not full";
        }
    }
    void isempty(){
         if (top == -1) {
            cout << "stack is empty"<<endl;
            return;
        }else{
            cout << "stack is not empty";
        }
    }
};

int main() {
    int capacity;
    cout << "enter stack capacity: ";
    cin >> capacity;

    stack s(capacity);
    int choice;

    while (true) {
        cout << endl << "--- STACK MENU ---"<< endl;
        cout << "1. push";
        cout << "2. pop";
        cout << "3. peek";
        cout << "4. display";
        cout << "5. exit";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice";
        }
    }
}
