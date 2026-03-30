#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Account 
{
    private:
        string name;
        double balance;

    public:
        // Parametreli kurucu method ve üye ilklendirme listesi
        Account(string accountName, double initialBalance):
            name(accountName), balance(0.0)
            //Başlangıçta balance'ı 0.0 olarak atıyoruz, çünkü negatif bir değer kabul edilmeyecek
        {
            if (initialBalance < 0) 
            {
                throw invalid_argument("Balance cannot be negative");
            }
            this->balance = initialBalance;
        }
    
    // C++11 defalut yıkıcı methodu (Destructor)
    ~Account() = default;

    // Ayarlayıcı method(Setter)
    void deposit(double depositAmount) 
    {
        if (depositAmount < 0.0) 
        {
            throw invalid_argument("Deposit amount cannot be negative");
        }
        balance += depositAmount;
    }

    // Alıcı method(Getter)- const doğruluğu (const correctness)
    double getBalance() const
    {
        return balance;
    }
    string getName() const
    {
        return name;
    }
}
