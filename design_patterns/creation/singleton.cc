/*! @file singleton.cc
 *  @brief Singleton Creational Pattern example
 *
 *  The Singleton Creational Pattern is that restricts the 
 *  instantiation of a class to one object. This is useful
 *  when exactly one object is needed to coordinate action 
 *  across the system.
 *
 *  # The abstract factory, builder and prototype patterns can 
 *  use Singletons in their implementation.
 *
 *  # Facade objects are often singletons beacause only one 
 *  Facade object is required.
 *
 *  # State objects are often singleton.
 *
 *  # Singletons are often preferred to global variables because: 
 *      They do not pollute the global namespace with unnecessary variables.
 *      They permit lazy allocation and initialization, whereas global 
 *      variables in many languages will always consume resources.
 */
#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton* GetInstance() {
        if (!my_singleton_instance_) {
            my_singleton_instance_ = new Singleton();
            if (!my_singleton_instance_)
                my_singleton_instance_ = new Singleton();
        }
        cout << "get singleton instance " << my_singleton_instance_ << endl;
        return my_singleton_instance_;
    }
    static Singleton* Create() {
        my_singleton_instance_ = new Singleton();
        cout << "create singleton instance " << my_singleton_instance_ << endl;
        return my_singleton_instance_;
    }
    ~Singleton() {}
private:
    static Singleton *my_singleton_instance_;
    Singleton() {}
};

Singleton* Singleton::my_singleton_instance_ = NULL;

int main(void) {
    Singleton *instance = Singleton::Create();
    Singleton *instance_get = Singleton::GetInstance();
    cout << instance << ":" << instance_get << endl;
    return 0;
}

