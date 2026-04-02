#include <iostream>
#include <string>
using namespace std;

class Sensor
{
    protected:
        string sensorName;
        float rawValue;
    public:
        Sensor(string name, float value = 0.0) : sensorName(name), rawValue(value) {}

        void setRawValue(float value)
        {
            rawValue = value;
        }
        virtual float processData() const 
        {
            return rawValue;
        }
        virtual void display() const
        {
            cout << "Sensor: " << sensorName << endl;
            cout << "Raw Value: " << rawValue << endl;
        }
        virtual ~Sensor() {}       
};

class UltrasonicSensor : public Sensor
{
    private:
        float offset;
    public:
        UltrasonicSensor(string name, float osvalue) : Sensor(name), offset(osvalue) {}

        float processData() const override
        {
            return ((rawValue * 0.0343) / 2) + offset;
        }
        void display() const override
        {
            cout << "---- Ultrasonic Sensor ----" << endl;
            Sensor::display();
            cout << "Hesaplanan Mesafe: " << processData() << "cm" << endl;
        }
        virtual ~UltrasonicSensor() = default;
};

class TemperatureSensor : public Sensor
{
    public:
        TemperatureSensor(string name, float value) : Sensor(name, value) {}

        float processData() const override
        {
            return (rawValue / 1023.0) * 500.0;
        }
        void display() const override
        {
            cout << "---- Temperature Sensor ----" << endl;
            Sensor::display();
            cout << "Hesaplanan Sicaklik:" << processData() << "°C" << endl;
        }
        virtual ~TemperatureSensor() = default;
};

int main()
{
    UltrasonicSensor us1("On-Mesafe-Algilayici", 2.5);
    us1.setRawValue(1450.0);
    us1.display();
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << endl;

    TemperatureSensor ts1("Motor-Sicaklik-Algilayici", 155.0);
    ts1.display();

    return 0;
}