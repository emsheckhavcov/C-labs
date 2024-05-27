#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Car {
    string model;
    string manufacturer;
    int year;
    string vin;
    string owner;
};

class CarRegistryDB {
public:
    CarRegistryDB(const string &filename) : filename(filename) {
        load();
    }

    ~CarRegistryDB() {
        save();
    }

    void addCar(const Car &car) {
        cars.push_back(car);
        save();
    }

    void editCar(int index, const Car &updatedCar) {
        if (index >= 0 && index < cars.size()) {
            cars[index] = updatedCar;
            save();
        }
    }

    void deleteCar(int index) {
        if (index >= 0 && index < cars.size()) {
            cars.erase(cars.begin() + index);
            save();
        }
    }

    vector<Car> searchCars(const string &query) {
        vector<Car> results;
        for (const auto &car : cars) {
            if (car.model.find(query) != string::npos ||
                car.manufacturer.find(query) != string::npos ||
                car.vin.find(query) != string::npos ||
                car.owner.find(query) != string::npos) {
                results.push_back(car);
            }
        }
        return results;
    }

    vector<Car> listCars() {
        return cars;
    }

private:
    string filename;
    vector<Car> cars;

    void load() {
        ifstream file(filename);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Car car;
            getline(ss, car.model, ',');
            getline(ss, car.manufacturer, ',');
            ss >> car.year;
            ss.ignore();
            getline(ss, car.vin, ',');
            getline(ss, car.owner, ',');
            cars.push_back(car);
        }
    }

    void save() {
        ofstream file(filename);
        for (const auto &car : cars) {
            file << car.model << ","
                 << car.manufacturer << ","
                 << car.year << ","
                 << car.vin << ","
                 << car.owner << "\n";
        }
    }
};

void printCar(const Car &car) {
    cout << "Model: " << car.model
         << ", Manufacturer: " << car.manufacturer
         << ", Year: " << car.year
         << ", VIN: " << car.vin
         << ", Owner: " << car.owner << endl;
}

int main() {
    CarRegistryDB db("car_registry.txt");

    string command;
    while (true) {
        cout << "\nCommands: add, edit, delete, search, list, exit\n";
        cout << "Enter command: ";
        cin >> command;

        if (command == "add") {
            Car car;
            cout << "Model: "; cin >> car.model;
            cout << "Manufacturer: "; cin >> car.manufacturer;
            cout << "Year: "; cin >> car.year;
            cout << "VIN: "; cin >> car.vin;
            cout << "Owner: "; cin >> car.owner;
            db.addCar(car);
            cout << "Car added." << endl;
        } else if (command == "edit") {
            int index;
            cout << "Enter index to edit: "; cin >> index;
            Car car;
            cout << "Model: "; cin >> car.model;
            cout << "Manufacturer: "; cin >> car.manufacturer;
            cout << "Year: "; cin >> car.year;
            cout << "VIN: "; cin >> car.vin;
            cout << "Owner: "; cin >> car.owner;
            db.editCar(index, car);
            cout << "Car edited." << endl;
        } else if (command == "delete") {
            int index;
            cout << "Enter index to delete: "; cin >> index;
            db.deleteCar(index);
            cout << "Car deleted." << endl;
        } else if (command == "search") {
            string query;
            cout << "Enter search query: "; cin >> query;
            vector<Car> results = db.searchCars(query);
            cout << "Found " << results.size() << " cars:" << endl;
            for (const auto &car : results) {
                printCar(car);
            }
        } else if (command == "list") {
            vector<Car> cars = db.listCars();
            cout << "Total " << cars.size() << " cars:" << endl;
            for (size_t i = 0; i < cars.size(); ++i) {
                cout << i << ": ";
                printCar(cars[i]);
            }
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command. Try again." << endl;
        }
    }

    return 0;
}
