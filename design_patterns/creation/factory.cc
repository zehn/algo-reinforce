/*! @file factory.cpp
 *  @brief Factory Creational Pattern example
 *
 *  The Factory Design Pattern is useful in a situation that
 *  requires the creation of many different types of objects,
 *  all derived from a common base type. The Factory Method 
 *  defines a method for creating the objects, which subclasses 
 *  can then override to specify the derived type that will be 
 *  created. Thus, at run time, the Factory Method can be passed
 *  a description of a desired object and return a base class 
 *  pointer ot a new instance of the object.
 *
 *  If we want to decide at run time what object is to be created 
 *  based on some configuration or application parameter. When we 
 *  write the code, we do not know what class should be instantiated.
 *
 *  Define an interface for creating an object, but let subclasses 
 *  decide which class to instantiate.
 *
 *  The Factory Design Pattern works best when a well-designed 
 *  interface is used for the base class, so there is no need to 
 *  cast the return object.
 */
#include <iostream>

using namespace std;

class Computer {
public:
    virtual ~Computer() {}
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class Laptop : public Computer {
public:
    virtual ~Laptop() {}
    virtual void Run() {
        hibernating_ = true;    
        cout << "Laptop starts running." << endl;
    }
    virtual void Stop() {
        hibernating_ = false;
        cout << "Laptop stops running." << endl;
    }

private:
    bool hibernating_;
};

class Desktop : public Computer {
public:
    virtual ~Desktop() {}
    virtual void Run() {
        on_ = true;
        cout << "Desktop starts running." << endl;
    }
    virtual void Stop() {
        on_ = false;
        cout << "Desktop stops running." << endl;
    }

private:
    bool on_;
};

class ComputerFactory {
public:
    static Computer *CreateNew(const string &desc) {
        Computer *computer_to_produce = NULL;
        if ("laptop" == desc)
            computer_to_produce =  new Laptop();
        if ("desktop" == desc)
            computer_to_produce =  new Desktop();
        return computer_to_produce;
    }
};

int main(void) {
    Computer *my_computer1 = ComputerFactory::CreateNew("laptop");
    my_computer1->Run();
    my_computer1->Stop();

    Computer *my_computer2 = ComputerFactory::CreateNew("desktop");
    my_computer2->Run();
    my_computer2->Stop();

    delete my_computer1;
    delete my_computer2;
    return 0;
}

