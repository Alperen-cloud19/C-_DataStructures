#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. TEMEL SINIF (BASE CLASS)
class Employee 
{
    protected:
        string name;
    
    public:
        Employee(string name) : name(name) {}
        
        //ÇOK ÖNEMLİ: dynamic_cast (RTTI) kullanabilmek için temel sınıfta
        //en az bir sanal fonksiyon (virtual function) tanımlamalıyız.
        //Genellikle destructor'ı sanal yaparız.
        virtual ~Employee() = default;  // Virtual destructor

        // Polimorfik fonksiyon (virtual function)
        virtual double earnings() const 
        {
            return 0.0; // Temel sınıf için varsayılan kazanç
        }

        string getName() const 
        {
            return name;
        }
};

// 2. TÜRETİLMİŞ SINIFLAR (DERIVED CLASSES)
class BasePlusCommissionEmployee : public Employee
{
    private:
        double baseSalary;

    public:
        BasePlusCommissionEmployee(string name, double salary) :
            Employee(name), baseSalary(salary) {}

        // Bu sınıfa özel fonksiyonlar
        double getBaseSalary() const {return baseSalary;}
        void setBaseSalary(double salary) {baseSalary = salary;}

        // Temel sınıftaki fonksiyonu eziyor (override)
        double earnings() const override
        {
            // Normalde komisyon hesabı olurdu ama basit tutmak için
            // sadece base salary döndürüyoruz
            return baseSalary;
        }
};

// 3. FARKLI BİR ALT SINIF (Karşılaştırma yapmak için)
class HourlyEmployee : public Employee
{
    public:
        HourlyEmployee(string name) : Employee(name) {}

        // Bu sınıfın taban maaşı (baseSalary) yoktur.
        double earnings() const override
        {
            return 1500.0;  // Sabit bir kazanç döndürüyoruz
        }
};

// 4. ANA PROGRAM
int main()
{
    // Farklı çalışan türlerini tutacak bir vektör
    vector<Employee*> employees;

    // Listeye çalışanları ekleyelim
    employees.push_back(new HourlyEmployee("Ahmet (Saatlik)"));
    employees.push_back(new BasePlusCommissionEmployee("Mesut", 3000.0));
    employees.push_back(new BasePlusCommissionEmployee("Ayse", 4500.0));

    cout << "--- Zam Islemi Basliyor --- \n" << endl;

    for (size_t i = 0; i < employees.size(); i++)
    {
        // İşaretçiyi al
        Employee* empPtr = employees[i];

        // 1. Polimorfik işleme örneği (Dinamik bağlama ile 
        // kendi earnings() fonsiyonu çalışır.)
        cout << empPtr->getName() << " kazanci: " << empPtr->earnings() << "TL"<< endl;

        // 2. Sadece BasePlusCommissionEmployee türündeki çalışanlara %10 zam yapalım
        BasePlusCommissionEmployee* derivedPtr = 
            dynamic_cast<BasePlusCommissionEmployee*>(empPtr);

        // 3. Eğer empPtr gerçekten o tipi gösteriyorsa basePtr nullptr olmaz
        if (derivedPtr != nullptr) 
        {
            double oldSalary = derivedPtr->getBaseSalary();
            derivedPtr->setBaseSalary(oldSalary * 1.10); // %10 zam
            
            cout << "=> DURUM: Basarili! Bu kisi bir Maasli calisan. %10 zam yapildi." << endl;
            cout << "=> Yeni kazanci: " << derivedPtr->getBaseSalary() << "TL" << endl;
        }
        else
        {
            // Eğer saatlik çalışansa derivedPtr nullptr olur ve bu bloğa gireriz.
            cout << "=> DURUM: Bu kisi bir Maasli calisan degil. Zam yapilamaz." << endl;
        }
    }
    // Hafıza sızıntısını önlemek için oluşturulan nesneleri silmeyi unutmayalım
    for (Employee* emp : employees)
    {
        delete emp;
    }
    return 0;
}