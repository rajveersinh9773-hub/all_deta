#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ids;
    vector<string> names;

    int no;
    cout<<endl << "enter number of students: ";
    cin >> no;

    for (int i = 0; i < no; i++) {
        int id;
        string name;

        cout<<endl << "enter id for student " << i+1 << "  ";
        cin >> id;
        cout << "enter name for student " << i+1 << "  ";
        cin >> name;

        ids.push_back(id);
        names.push_back(name);
    }

    cout<<endl << "student list" << endl;

    for (int i = 0; i < ids.size(); i++) {
        cout << "id : " << ids[i]
             << "name : " << names[i] << endl;
    }

    return 0;

}