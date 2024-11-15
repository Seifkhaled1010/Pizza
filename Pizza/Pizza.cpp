#include <iostream>
#include "Pizza.h"
using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

class Pizza
{
    void MakePizzaDough()
    {
        cout << "Making pizza dough!" << endl;
    }

    void BakePizza()
    {
        cout << "Baking Pizza!" << endl;
    }

protected:
    virtual void AddToppings() = 0;

public:
    void MakePizza()
    {
        MakePizzaDough();
        AddToppings();
        BakePizza();
    }
};

class BeefPizza : public Pizza
{
protected:
    void AddToppings()
    {
        cout << "Adding beef toppings!" << endl;
    }
};

class Beefpizzastuffedcrust : public BeefPizza
{
    void AddToppings()
    {
        cout << "Stuffedcrust Beef pizza" << endl;
    }
};

class Beefpizzathin : public BeefPizza
{
    void AddToppings()
    {
        cout << "Thin Beef Pizza" << endl;
    }
};

class ChickenPizza : public Pizza
{
    void AddToppings()
    {
        cout << "Adding chicken toppings!" << endl;
    }
};

class ShrimpPizza : public Pizza
{
    void AddToppings()
    {
        cout << "Adding shrimp toppings!" << endl;
    }
};

void kokowawa(Pizza* p)
{
    p->MakePizza();
}

void main()
{
    int choice;
    cout << "Please enter pizza choice (1 for beef, 2 for chicken, 3 for shrimp): ";
    cin >> choice;
    Pizza* pizza = 0;
    switch (choice) {

    case 1:
        pizza = new BeefPizza();
        break;

    case 2:
        pizza = new ChickenPizza();
        break;

    case 3:
        pizza = new ShrimpPizza();
        break;
    default:
        break;
    }
    if (instanceof<BeefPizza>(pizza))
    {
        int type;
        cout << "Press 1 for stuffedcrust Beef, 2 for Thin Beef: " ;
        cin >> type;
        switch (type)
        {
        case 1: 
            pizza = new Beefpizzastuffedcrust();
            break;

        case 2:
            pizza = new Beefpizzathin();
            break;

        default:
            break;
        }
    }

    kokowawa(pizza);
    delete pizza;
}