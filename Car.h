#include <string>

class Car {
    private:
        int yearModel;
        std::string make;
        int speed;
    public:
        Car(int, std::string);
        int getModel() const {
            return yearModel;
        }
        std::string getMake() const {
            return make;
        }
        int getSpeed() const {
            return speed;
        }
        void accelerate() {
            speed += 5;
        }
        void brake() {
            speed -= 5;
        }
};