#include "datavalidation.h"
#include "Car.h"

using namespace std;

Car::Car(int yearModel, std::string make) {
    this->yearModel = yearModel;
    this->make = make;
    speed = 0;
}

int main() {
    Car car(2000, "AmoguCar");
    for (int i = 0; i < 5; i++) {
        car.accelerate();
    }
    cout << car.getSpeed() << endl;
    for (int i = 0; i < 5; i++) {
        car.brake();
    }
    cout << car.getSpeed() << endl;
    cout << car.getMake() << endl;
    cout << car.getModel() << endl;

    return 0;
}