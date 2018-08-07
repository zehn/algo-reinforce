#include <iostream>

class Hindu {
public:
    virtual ~Hindu() = default;
    virtual void performsHinduRitual() const = 0;
};

class HinduFemale : public Hindu {
public:
    virtual void performsHinduRitual() const override {
        std::cout << "Hindu girl performs Hindu ritual." << std::endl;
    }
};

class Muslim {
public:
    virtual ~Muslim() = default;
    virtual void performsMuslinRitual() const = 0;
};

class MuslimFemale : public Muslim {
public:
    virtual void performsMuslinRitual() const override {
        std::cout << "Muslin girl performs Muslim ritual." << std::endl;
    }
};

class HinduRitual {
public:
    void carryOutRitual(Hindu* hindu) {
        std::cout << "On with the Hindu rituals!" << std::endl;
        hindu->performsHinduRitual();
    }
};

// convert the interface of a class into another interface that clients expect.
// Adapter let classes work together that counldn't otherwise bacause of
// incompatible interfaces.
class HinduAdapter : public Hindu {
private:
    Muslim* muslim;
public:
    HinduAdapter(Muslim* m) : muslim(m) {}
    virtual void performsHinduRitual() const override {
        muslim->performsMuslinRitual();
    }
};

int main() 
{
    HinduFemale* hinduGirl = new HinduFemale;
    MuslimFemale* muslimGirl = new MuslimFemale;

    HinduRitual hinduRitual;

    // will not compile of course since the parameter must be of type Hindu*
    //hinduRitual.carryOutRitual(muslimGirl);

    // muslimGirl has adapted to become a Hindu
    HinduAdapter* adapterMuslim = new HinduAdapter(muslimGirl);

    hinduRitual.carryOutRitual(hinduGirl);
    hinduRitual.carryOutRitual(adapterMuslim);

    delete adapterMuslim;
    delete muslimGirl;
    delete hinduGirl;

    return 0;
}

