#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* brand;
    char* model;
    float price;

public:
    Car(const char* brand, const char* model, float price) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        
        this->price = price;
    }

    ~Car() {
        delete[] brand;
        delete[] model;
    }

    void display() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Car car1("Toyota", "Camry", 800630.50);
    car1.display();

    return 0;
}
