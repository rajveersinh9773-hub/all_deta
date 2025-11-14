#include <iostream>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    Vehicle(int id=0, string m="NA", string mo="NA", int y=0) {
        vehicleID = id;
        manufacturer = m;
        model = mo;
        year = y;
    }

    int getId() { return vehicleID; }

    virtual void display() {
        cout << "ID: " << vehicleID
             << " | " << manufacturer
             << " " << model
             << " | Year: " << year;
    }
};

class Car : public Vehicle {
    string fuelType;
public:
    Car(int id,string m,string mo,int y,string fuel)
        : Vehicle(id,m,mo,y), fuelType(fuel) {}

    void display() override {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};

class ElectricCar : public Car {
    int battery;
public:
    ElectricCar(int id,string m,string mo,int y,string fuel,int b)
        : Car(id,m,mo,y,fuel), battery(b) {}

    void display() override {
        Car::display();
        cout << " | Battery: " << battery << " kWh";
    }
};

class VehicleRegistry {
    Vehicle* list[20];   
    int count = 0;       
public:
    void add(Vehicle* v) {
        if(count < 20) {
            list[count] = v;
            count++;
        } else {
            cout << "Registry full!\n";
        }
    }

    void showAll() {
        if(count == 0) {
            cout << "No vehicles in registry.\n";
            return;
        }
        for(int i=0; i<count; i++) {
            list[i]->display();
            cout << endl;
        }
    }

    void searchById(int id) {
        for(int i=0; i<count; i++) {
            if(list[i]->getId() == id) {
                list[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

int main() {
    VehicleRegistry reg;
    int choice;

    do {
        cout << "\n--- Vehicle Menu ---\n";
        cout << "1. Add Car\n";
        cout << "2. Add ElectricCar\n";
        cout << "3. Show All Vehicles\n";
        cout << "4. Search by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            int id, year;
            string manu, model, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, Fuel: ";
            cin >> id >> manu >> model >> year >> fuel;
            reg.add(new Car(id, manu, model, year, fuel));
        }
        else if(choice == 2) {
            int id, year, battery;
            string manu, model, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, Fuel, Battery: ";
            cin >> id >> manu >> model >> year >> fuel >> battery;
            reg.add(new ElectricCar(id, manu, model, year, fuel, battery));
        }
        else if(choice == 3) {
            reg.showAll();
        }
        else if(choice == 4) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            reg.searchById(id);
        }

    } while(choice != 5);

    return 0;
}
