/*! @file observer.cc
 *  @brief Observer Pattern example
 *
 *  The observer pattern is a software design pattern in which an object, 
 *  called the subject, maintains a list of its dependents, called observers,
 *  and notifies them automatically of any state changes, usually by calling 
 *  one of their methods.
 *
 *  The observer pattern can cause memory leaks, known as the lapsed listener 
 *  problem, because in basic implementation it requires both explicit 
 *  registration and deregistration, as in the dispose pattern, because the 
 *  subject holds strong references to the observers, keeping them alive.
 *  This can be prevented by the subject holding weak references to the
 *  observers
 */
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class Subject;

class Observer {
public:
    virtual void Print(Subject *) = 0;
    virtual ~Observer() {}
protected:
    Observer() {}
};

class Subject {
public:
    void Notify();
    void Regsiter(Observer *ob);
    void Deregister(Observer *ob);
    virtual ~Subject() {}
protected:
    Subject() {}
private:
    list<Observer* > obs_;
};

void Subject::Notify() {
    list<Observer* >::iterator it;
    for (it = obs_.begin(); it != obs_.end(); ++it)
        (*it)->Print(this);
}

void Subject::Regsiter(Observer *ob) {
    obs_.push_back(ob);
}

void Subject::Deregister(Observer *ob) {
    list<Observer* >::iterator it;
    it = find(obs_.begin(), obs_.end(), ob);
    if (obs_.end() != it)
        obs_.erase(it);
}

class Kid : public Observer {
public:
    void Print(Subject *sub) {
        cout << myname_ << ": The worm(" << sub << ") is crawling" << endl;
    }
    virtual ~Kid() {}
    Kid(std::string name) : myname_(name) {}
private:
    string myname_;
};

class Worm : public Subject {
public:
    virtual ~Worm() {}
    Worm() {}
};

int main(void) {
    Kid my_elder_son("Tonny");
    Kid my_younger_son("Tim");

    Worm caterpillar;
    caterpillar.Regsiter(&my_elder_son);
    caterpillar.Regsiter(&my_younger_son);
    caterpillar.Notify();
    
    caterpillar.Deregister(&my_elder_son);
    caterpillar.Notify();

    return 0;
}

