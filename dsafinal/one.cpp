#include <iostream>
#include <queue>
using namespace std;

void displayall(queue<int> q) {
    cout << "queue all element: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void update(queue<int>& q) {
    if (q.empty()) {
        cout << "queue is empty" << endl;
        return;
    }

    int index, newvalue;
    cout << "enter index you want to update: ";
    cin >> index;
    cout << "enter new value: ";
    cin >> newvalue;

    queue<int> temp;
    int i = 0;
    bool updated = false;

    while (!q.empty()) {
        if (i == index) {
            temp.push(newvalue);
            updated = true;
        } else {
            temp.push(q.front());
        }
        q.pop();
        i++;
    }

    q = temp;

    if (updated)
        cout << "queue successfully updated" << endl;
    else
        cout << "invalid index" << endl;
}

int main() {
    cout << "welcome to crud operations" << endl;

    queue<int> q;
    int choice, value;

    while (true) {
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. display" << endl;
        cout << "4. update" << endl;
        cout << "5. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter value: ";
            cin >> value;
            q.push(value);
            break;

        case 2:
            if (!q.empty()) {
                q.pop();
                cout << "dequeued" << endl;
            } else {
                cout << "queue is empty" << endl;
            }
            break;

        case 3:
            displayall(q);
            break;

        case 4:
            update(q);
            break;

        case 5:
            return 0;

        default:
            cout << "invalid choice" << endl;
        }
    }
}
