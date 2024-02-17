#include <iostream>
#include <string>

using namespace std;

class Beverage {
public:
    virtual ~Beverage() = default;
    virtual string getDescription() const {
        return description;
    }
    virtual double cost() const = 0;

protected:
    string description = "Unknown Beverage";
};


class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() const override {
        return 1.99;
    }
};


class DarkRoast : public Beverage {
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() const override {
        return 0.99;
    }
};


class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() const = 0;
};


class Whip : public CondimentDecorator {
    Beverage* beverage;

public:
    Whip(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const override {
        return 0.10 + beverage->cost();
    }
};


class Milk : public CondimentDecorator {
    Beverage* beverage;

public:
    Milk(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return 0.15 + beverage->cost();
    }
};


class Mocha : public CondimentDecorator {
    Beverage* beverage;

public:
    Mocha(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() const override {
        return 0.20 + beverage->cost();
    }
};


class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }

    double cost() const override {
        return 0.89;
    }
};


class Soy : public CondimentDecorator {
    Beverage* beverage;

public:
    Soy(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Soy";
    }

    double cost() const override {
        return 0.15 + beverage->cost();
    }
};


class TamañoGrande : public CondimentDecorator {
    Beverage* beverage;

public:
    TamañoGrande(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Grande";
    }

    double cost() const override {
        return 0.50 + beverage->cost();
    }
};


class Doble : public CondimentDecorator {
    Beverage* beverage;

public:
    Doble(Beverage* beverage) : beverage(beverage) {}

    string getDescription() const override {
        return beverage->getDescription() + ", Doble";
    }

    double cost() const override {
        return 1.50 + beverage->cost();
    }
};

int main() {
    
    Beverage* beverage1 = new Espresso();
    cout << beverage1->getDescription() << " $" << beverage1->cost() << endl;

    Beverage* beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    beverage2 = new Whip(beverage2);
    beverage2 = new Milk(beverage2);
    beverage2 = new TamañoGrande(beverage2);  
    cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

    Beverage* beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    beverage3 = new Doble(beverage3);  
    cout << beverage3->getDescription() << " $" << beverage3->cost() << endl;

    return 0;
}
