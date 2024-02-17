#include <iostream>

// Interfaz para las estrategias
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

// Implementación concreta de una estrategia
class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Ejecutando estrategia A" << std::endl;
    }
};

// Implementación concreta de otra estrategia
class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Ejecutando estrategia B" << std::endl;
    }
};

// Contexto que utiliza la estrategia
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    // Creamos las estrategias concretas
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    // Creamos el contexto con la estrategia A
    Context context(&strategyA);
    context.executeStrategy();

    // Cambiamos la estrategia del contexto a B y ejecutamos
    context.setStrategy(&strategyB);
    context.executeStrategy();

    return 0;
}

