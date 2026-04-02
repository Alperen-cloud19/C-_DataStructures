#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Temel sınıf (Base Class)
class Signal
{
    protected:
        float amplitude;
    public:
        Signal(float ampl) : amplitude(ampl) {}

        float getamplitude()
        {
            return amplitude;
        }
        void setamplitude(float ampli)
        {
            amplitude = ampli;
        }
        virtual void display() const
        {
            cout << "--- Base Signal Details ---" << endl;
            cout << "Signal amplitude: " << amplitude <<"V"<< endl;
            cout << "----------------------------" << endl;
        }

        virtual float calcPower() const
        {
            return (amplitude * amplitude) / 2.0; // Güç = (amplitude^2) / 2
        }

        virtual float calcRMS() const
        {
            return amplitude / sqrt(2); // RMS = amplitude / sqrt(2)
        }

        virtual ~Signal() = default; // Virtual destructor for proper cleanup
};

// Türetilmiş sınıf (Derived Class)
class PWMSignal : public Signal
{
    private:
        float dutyCycle;
    public:
        PWMSignal(float amp, float dc) : Signal(amp), dutyCycle(dc) {}

        void setdutycycle(float dc)
        {
            dutyCycle = dc;
        }
        float getdutycycle()
        {
            return dutyCycle;
        }
        void display() const override
        {
            cout << "--- PWM Signal Details ---" << endl;
            cout << "Signal Amplitude: " << amplitude << "V" << endl;
            cout << "Duty Cycle: " << dutyCycle << "%" << endl;
            cout << "----------------------------" << endl;
        }

        float calcPower() const override
        {
            return (amplitude * amplitude) * dutyCycle / 100.0; // Güç = (amplitude^2) * (dutyCycle / 100)
        }
        float calcRMS() const override
        {
            return amplitude * dutyCycle / 100.0; // RMS = amplitude * (dutyCycle / 100)
        }

        virtual ~PWMSignal() = default; //Virtual destructor fonksiyonu, 
                                        //türetilmiş sınıfın kaynaklarını düzgün bir şekilde temizlemek için 
};

int main()
{
    Signal signal1(5.0); // Temel sınıf nesnesi
    signal1.display();
    cout << "Pure Signal Power: " << signal1.calcPower() << "W" << endl;
    cout << "Pure Signal RMS: " << signal1.calcRMS() << "V" << endl;
    cout << endl;
    cout << "----------------------------" << endl;
    cout << endl;

    PWMSignal pwmsignal1(12.0, 75.0); // Türetilmiş sınıf nesnesi
    pwmsignal1.display();
    cout << "PWM Signal Power: " << pwmsignal1.calcPower() << "W" << endl;
    cout << "PWM Signal RMS: " << pwmsignal1.calcRMS() << "V" << endl;
    cout << endl;
    cout << "----------------------------" << endl;
    cout << endl;

    return 0;
}