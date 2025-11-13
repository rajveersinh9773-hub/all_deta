#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:

    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }


    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int number) { trainNumber = number; }
    int getTrainNumber() const { return trainNumber; }

    void setTrainName(const char* name) { strcpy(trainName, name); }
    const char* getTrainName() const { return trainName; }

    void setSource(const char* src) { strcpy(source, src); }
    const char* getSource() const { return source; }

    void setDestination(const char* dest) { strcpy(destination, dest); }
    const char* getDestination() const { return destination; }

    void setTrainTime(const char* time) { strcpy(trainTime, time); }
    const char* getTrainTime() const { return trainTime; }


    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTrain Time: " << trainTime << endl;
    }


    static int getTrainCount() {
        return trainCount;
    }
};


int Train::trainCount = 0;


int main() {
    Train t1;
    t1.inputTrainDetails();

    Train t2(1234, "Express", "Delhi", "Mumbai", "08:30");

    cout << "\n--- Train Details ---";
    t1.displayTrainDetails();
    t2.displayTrainDetails();

    cout << "\nTotal Trains: " << Train::getTrainCount() << endl;

    return 0;
}
