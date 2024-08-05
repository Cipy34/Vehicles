#include <iostream>
#include <string>

using namespace std;

class Vehicle{
private:
    int speedLevel;
    float price;
public:
    Vehicle(){
        speedLevel = 0;
        price = 0;
    }

    Vehicle(const int speedLevel, const float price){
        this->speedLevel = speedLevel;
        this->price = price;
    }

    void setSpeedLevel(const int speedLevel){
        this->speedLevel = speedLevel;
    }

    void setPrice(const float price){
        this->price = price;
    }

    int getSpeedLevel() const{
        return this->speedLevel;
    }

    float getPrice() const{
        return this->price;
    }

    virtual void description() const = 0;

};

class Car : public Vehicle{
private:
    string type;
public:
    Car() : Vehicle(){
        this->type = "";
    }

    Car(const int speedLevel, const float price, const string type) : Vehicle(speedLevel, price){
        this->type = type;
    }

    void setType(const string type){
        this->type = type;
    }

    string getType() const{
        return this->type;
    }

    void description() const override{
        cout<<"Bad for the plannet, but very fast!";
    }
};

class ElectricCar : public Car{
private:
    int batteryLevel;
public:
    ElectricCar() : Car(){
        this->batteryLevel = 0;
    }

    ElectricCar(const int speedLevel, const float price, const string type, const int batteryLevel) : Car(speedLevel, price, type){
        this->batteryLevel = batteryLevel;
    }

    void setBatteryLevel(const int batteryLevel){
        this->batteryLevel = batteryLevel;
    }

    int getBatteryLevel() const{
        return this->batteryLevel;
    }

    void description() const override{
        cout<<"Good for the planet and very fast!";
    }
};

class Bike : public Vehicle{
private:
    string ridingType;
public:
    Bike() : Vehicle(){
        this->ridingType = "";
    }

    Bike(const int speedLevel, const float price, const string ridingType) : Vehicle(speedLevel, price){
        this->ridingType = ridingType;
    }

    void setRidingType(const string ridingType){
        this->ridingType = ridingType;
    }

    string getRidingType() const{
        return this->ridingType;
    }

    void description() const override{
        cout<<"Good for the planet and good for the health!";
    }
};

class Truck : public Vehicle{
private:
    float loadCapacity;
public:
    Truck() : Vehicle(){
        this->loadCapacity = 0;
    }

    Truck(const int speedLevel, const float price, const float loadCapacity) : Vehicle(speedLevel, price){
        this->loadCapacity = loadCapacity;
    }

    void setLoadCapacity(const float loadCapacity){
        this->loadCapacity = loadCapacity;
    }

    float getLoadCapacity() const{
        return this->loadCapacity;
    }

    void description() const override{
        cout<<"Bad for the planet, but good for the load capacity";
    }
};

int main() {
    Vehicle* v1 = new Car(120, 30000, "Sports Car");
    v1->description();

    Vehicle* v2 = new ElectricCar(150, 40000, "Sedan", 80);
    v2->description();

    Vehicle* v3 = new Bike(30, 500, "Mountain Bike");
    v3->description();

    Vehicle* v4 = new Truck(80, 50000, 1000);
    v4->description();

    // Clean up
    delete v1;
    delete v2;
    delete v3;
    delete v4;

    return 0;
}
