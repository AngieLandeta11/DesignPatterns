#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
    virtual void update() = 0;
};

class DisplayElement
{
public:
    virtual void display() = 0;
};

class Subject
{
public:
    virtual float getTemperature() const = 0;
    virtual float getHumidity() const = 0;
    virtual float getPressure() const = 0;
    virtual void addRegister(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherData : public Subject
{
private:
    float temperature;
    float humidity;
    float pressure;
    vector<Observer*> observers;

public:
    WeatherData()
    {
        observers = vector<Observer*>();
    }

    void addRegister(Observer* observer)
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {}

    void notifyObservers()
    {
        for (Observer* observer : observers)
        {
            observer->update();
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }

    float getTemperature() const
    {
        return temperature;
    }

    float getHumidity() const
    {
        return humidity;
    }

    float getPressure() const
    {
        return pressure;
    }
};

class StatisticsDisplay : public Observer, public DisplayElement
{
private:
    float maxTemp = 0.0f;
    float minTemp = 200;
    float tempSum = 0.0f;
    int numReadings;
    Subject* weatherData;

public:
    StatisticsDisplay(Subject* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->addRegister(this);
    }

    void update()
    {
        float temperature = weatherData->getTemperature();
        tempSum += temperature;
        numReadings++;

        if (temperature > maxTemp)
        {
            maxTemp = temperature;
        }

        if (temperature < minTemp)
        {
            minTemp = temperature;
        }

        display();
    }

    void display()
    {
        cout << "Avg/Max/Min temperature = " << (tempSum / numReadings) << "/" << maxTemp << "/" << minTemp << endl;
    }
};

class ForecastDisplay : public Observer, public DisplayElement
{
private:
    float currentPressure = 29.92f;
    float lastPressure;
    WeatherData* weatherData;

public:
    ForecastDisplay(WeatherData* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->addRegister(this);
    }

    void update()
    {
        float pressure = weatherData->getPressure();
        lastPressure = currentPressure;
        currentPressure = pressure;

        display();
    }

    void display()
    {
        cout << "Forecast: ";
        if (currentPressure > lastPressure)
        {
            cout << "Improving weather on the way!" << endl;
        }
        else if (currentPressure == lastPressure)
        {
            cout << "More of the same" << endl;
        }
        else if (currentPressure < lastPressure)
        {
            cout << "Watch out for cooler, rainy weather" << endl;
        }
    }
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    float pressure;
    Subject* weatherData;

public:
    CurrentConditionsDisplay(Subject* weatherData)
    {
        this->weatherData = weatherData;
        weatherData->addRegister(this);
    }

    void update()
    {
        temperature = weatherData->getTemperature();
        humidity = weatherData->getHumidity();
        pressure = weatherData->getPressure();

        display();
    }

    void display()
    {
        cout << "Current conditions: " << temperature << "F degrees, " << humidity << " humidity, and " << pressure << " pressure" << endl;
    }
};

int main()
{
    WeatherData weatherData;
    CurrentConditionsDisplay currentDisplay(&weatherData);
    StatisticsDisplay statisticsDisplay(&weatherData);
    ForecastDisplay forecastDisplay(&weatherData);

    weatherData.setMeasurements(80, 65, 30.4f);
    weatherData.setMeasurements(82, 70, 29.2f);
    weatherData.setMeasurements(78, 90, 29.2f);

    return 0;
}