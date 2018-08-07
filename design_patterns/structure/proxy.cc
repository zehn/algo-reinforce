/*! @file proxy.cc
 *  @brief Proxy Pattern Example
 */
#include <iostream>

using namespace std;

class Driver {
public:
    virtual void DriveCar() = 0;
};

class ProxyDriver : public Driver {
    void DriveCar() {
        cout << "The driver drived a car" << endl;
    }
};

class DesignatedDriver : public Driver {
private:
    Driver* real_driver_;
    unsigned drive_age_;
public:
    DesignatedDriver(int age) : drive_age_(age) {
        real_driver_ = new ProxyDriver();
    }
    void DriveCar() {
        if (16 < drive_age_) {
            real_driver_->DriveCar();
        } else {
            cout << "Sorry, the driver is too young to drive" << endl;
        }
    }
};

int main(void) {
    Driver *driver = new DesignatedDriver(16);
    driver->DriveCar();
    delete driver;
    driver = new DesignatedDriver(25);
    driver->DriveCar();
    delete driver;
    return 0;
}

