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
void bubblesort(queue<int>& q) {
    if (q.empty()) {
        cout << "queue is empty" << endl;
        return;
    }
    int n = q.size();
    for (int i = 0; i < n; i++) {
        queue<int> temp;
        int prev = q.front();
        q.pop();
        for (int j = 1; j < n - i; j++) {
            int curr = q.front();
            q.pop();

            if (prev > curr) {
                temp.push(curr);
            } else {
                temp.push(prev);
                prev = curr;
            }
        }
        temp.push(prev);
        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        q = temp;
    }

    cout << "queue sorted using bubble sort" << endl;
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
        cout << "5. bubble sort" << endl;
        cout << "6. exit" << endl;
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
            bubblesort(q);
            break;
        case 6:
            return 0;

        default:
            cout << "invalid choice" << endl;
        }
    }
}
