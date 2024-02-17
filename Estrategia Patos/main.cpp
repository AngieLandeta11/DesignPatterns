#include <iostream>

class FlyBehavior {
public:
    virtual void execute() = 0;
    virtual ~FlyBehavior() {}
};


class FlyWithWings : public FlyBehavior {
public:
    void execute() override {
        std::cout << "Estoy volando" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void execute() override {
        std::cout << "No puedo volar" << std::endl;
    }
};

class QuackBehavior {
public:
    virtual void execute() = 0;
    virtual ~QuackBehavior() {}
};

class Quack : public QuackBehavior {
public:
    void execute() override {
        std::cout << "Quack" << std::endl;
    }
};

class Squeack : public QuackBehavior {
public:
    void execute() override {
        std::cout << "Squeack" << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    void execute() override {
        std::cout << "No hago ruido" << std::endl;
    }
};

class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior)
        : flyBehavior(flyBehavior), quackBehavior(quackBehavior) {}

    void performQuack() {
        quackBehavior->execute();
    }

    virtual void swim() {
        std::cout << "Nadando" << std::endl;
    }

    virtual void display() = 0;

    void performFly() {
        flyBehavior->execute();
    }

    void showDuck() {
        display();
        performQuack();
        swim();
        performFly();
    }

    void setQuackBehavior(QuackBehavior* quackBehavior) {
        this->quackBehavior = quackBehavior;
    }

    void setFlyBehavior(FlyBehavior* flyBehavior) {
        this->flyBehavior = flyBehavior;
    }
};


class RedheadDuck : public Duck {
public:
    RedheadDuck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior)
        : Duck(flyBehavior, quackBehavior) {}

    void display() override {
        std::cout << "Soy un pato red head" << std::endl;
    }
};


class MallardDuck : public Duck {
public:
    MallardDuck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior)
        : Duck(flyBehavior, quackBehavior) {}

    void display() override {
        std::cout << "Soy un pato mallard" << std::endl;
    }
};

int main() {
    
    FlyWithWings flyWithWings;
    FlyNoWay flyNoWay;
    Quack quack;
    Squeack squeack;

    RedheadDuck redHead(&flyWithWings, &quack);
    MallardDuck mallard(&flyNoWay, &squeack);

    redHead.showDuck();
    std::cout << std::endl;
    mallard.showDuck();

    return 0;
}

