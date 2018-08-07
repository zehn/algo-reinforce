/*! @file builder.cc
 *  @brief Builder Creational Pattern example
 *
 *  The Builder Creational Pattern is used to seperate the 
 *  construction of a complex object from its representation
 *  so that the same construction process can create different
 *  objects representations.
 *  
 *  If we want to construct a complex object, however we do
 *  not want to have a complex constructor memeber or one that
 *  would need many arguments. We defined an intermedia object
 *  whose memeber functions define the desired object part by
 *  part before the object is available to the client.
 *  Builder Pattern lets us defer the construction of the object
 *  utill all the options for creation have been specified.
 */
#include <string>
#include <iostream>

using namespace std;

class Pizza {
public:
    void SetDough(const string &dough) {
        dough_ = dough;
    }
    void SetSauce(const string &sauce) {
        sauce_ = sauce;
    }
    void SetTopping(const string &topping) { 
        topping_ = topping; 
    }
    void Open() const {
        cout << "Pizza with " << dough_ << " dough, "
            << sauce_ << " sauce and " << topping_ << " topping." << endl;
    }
    
private:
    string dough_;
    string sauce_;
    string topping_;
};

class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}
    Pizza * GetPizza() {
        //return pizza_.get();
        return pizza_;
    }
    void MakeNewPizzaProduct() {
        //pizza_ = make_unique<Pizza>();
        pizza_ = new Pizza();
    }
    virtual void BuildDough() = 0;
    virtual void BuildSauce() = 0;
    virtual void BuildTopping() = 0;

protected:
    //unique_ptr<Pizza> pizza_; //!< -std=c++11, g++ version at least 4.6.x
    Pizza *pizza_;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    virtual ~HawaiianPizzaBuilder() {}
    virtual void BuildDough() {
        pizza_->SetDough("cross");
    }
    virtual void BuildSauce() {
        pizza_->SetSauce("mild");
    }
    virtual void BuildTopping() {
        pizza_->SetTopping("ham + pineapple");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
    virtual ~SpicyPizzaBuilder() {}
    virtual void BuildDough() {
        pizza_->SetDough("pan baked");
    }
    virtual void BuildSauce() {
        pizza_->SetSauce("hot");
    }
    virtual void BuildTopping() {
        pizza_->SetTopping("pepperoni + salaim");
    }
};

class Cook {
public:
    void OpenPizza() {
        pizza_builder_->GetPizza()->Open();
    }
    //! begin to make pizza
    void MakePizza(PizzaBuilder *pb) {
        pizza_builder_ = pb;
        pizza_builder_->MakeNewPizzaProduct();
        pizza_builder_->BuildDough();
        pizza_builder_->BuildSauce();
        pizza_builder_->BuildTopping();
    }

private:
    PizzaBuilder *pizza_builder_;
}; 

int main(int argc, char *argv[])
{
    Cook cook;
    HawaiianPizzaBuilder hpBuilder;
    SpicyPizzaBuilder    spBuilder;

    cook.MakePizza(&hpBuilder);
    cook.OpenPizza();
    
    cook.MakePizza(&spBuilder);
    cook.OpenPizza();

    return 0;
}
