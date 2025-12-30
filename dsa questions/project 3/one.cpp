#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedlist {
private:
    node* head;

public:

    linkedlist() {
        head = NULL;
    }


    void insert(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->next = head;
        head = newnode;
        cout << "node inserted\n";
    }


    void display() {
        if (head == NULL) {
            cout << "list is empty\n";
            return;
        }

        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }

  
    void search(int key) {
        node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "value found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "value not found\n";
    }


    void update(int oldval, int newval) {
        node* temp = head;

        while (temp != NULL) {
            if (temp->data == oldval) {
                temp->data = newval;
                cout << "node updated\n";
                return;
            }
            temp = temp->next;
        }
        cout << "value not found\n";
    }


    void remove(int value) {
        if (head == NULL) {
            cout << "list is empty\n";
            return;
        }

        if (head->data == value) {
            node* del = head;
            head = head->next;
            delete del;
            cout << "node deleted\n";
            return;
        }

        node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "value not found\n";
        } else {
            node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "node deleted\n";
        }
    }


    void reverse() {
        node* prev = NULL;
        node* curr = head;
        node* nextnode = NULL;

        while (curr != NULL) {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }

        head = prev;
        cout << "list reversed\n";
    }
};


int main() {
    linkedlist list;
    int choice, value, oldval, newval;

    do {
        cout << "\n1 insert\n2 display\n3 search\n4 update\n5 delete\n6 reverse\n7 exit\n";
        cout << "enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter value: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                list.display();
                break;

            case 3:
                cout << "enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 4:
                cout << "enter old value: ";
                cin >> oldval;
                cout << "enter new value: ";
                cin >> newval;
                list.update(oldval, newval);
                break;

            case 5:
                cout << "enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;

            case 6:
                list.reverse();
                break;

            case 7:
                cout << "exit\n";
                break;

            default:
                cout << "invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
