#include <iostream>
#include <string>
using namespace std;

// Base class
class CommisionEmployee 
{
    private :   // Veriler private, alt sınıflar tarafından doğrudan erişilemez
        string firstName;
        string lastName;
        double grossSales; // Brüt satışlar
        double commissionRate; // Komisyon oranı

    public :    // Üyeler public, alt sınıflar tarafından erişilebilir
        CommisionEmployee(const string &first, const string &last, double sales, double rate):
            firstName(first), lastName(last), grossSales(sales), commissionRate(rate)
        {
            //this->firstName = first;
            //this->lastName = last;
            //this->grossSales = sales;
            //this->commissionRate = rate;
        }
        
        // Sanal Yıkıcı (virtual destructor) ekleyelim, 
        //böylece alt sınıfların yıkıcıları doğru şekilde çağrılır
        virtual ~CommisionEmployee() = default;

        // Getter ve Setter fonksiyonları
        // Alıcılar (Getters)
        string getFirstName() const { return firstName;}
        string getLastName() const { return lastName;}
        double getGrossSales() const { return grossSales;}
        double getCommissionRate() const { return commissionRate;}
        
        // Sanal fonksiyon tanımlanması, polimorfizm'e hazırlık
        virtual double earnings() const
        {
            return getGrossSales() * getCommissionRate();
        }
        virtual void print() const
        {
            cout << "Commision Employee: " << getFirstName() << " " << getLastName() << endl;
         }
};

// Türetilmiş sınıf 
class BasePlusCommisionEmployee : public CommisionEmployee
{
    private:
        double baseSalary; // Temel maaş
    
    public:
        BasePlusCommisionEmployee(const string &first, const string &last, double sales, 
        double rate, double salary) :
            CommisionEmployee(first, last, sales, rate), baseSalary(salary)
            {
                // Kurucu metod zincirlemesi (Constructor chaining) ile 
                //temel sınıfa parametreler aktarımı
            }
            
            // Fonksiyonların geçersiz kılınması (Overriding)
            double earnings() const override
            {
                // Temel sınıfın fonksiyonunu çağırarak kod tekrarını önleme 
                // Temel maaş + (Brüt satışlar * Komisyon oranı)
                return baseSalary + CommisionEmployee::earnings();
            }
            void print() const override
            {
                cout << "Base Plus Commision Employee:" << getFirstName() << " " << getLastName() << endl;
                cout << "Base Salary: " << baseSalary << endl;
                cout << "Gross Sales: " << getGrossSales() << endl;
                cout << "Commision Rate: " << getCommissionRate() << endl;
                
                // Kapsül (scope) operatörü (::) ile sonsuz döngüden kaçınma
                // Temel sınıfın print fonksiyonunu çağırarak bilgileri yazdırma
                CommisionEmployee::print(); 
            }
};

int main()
{
    // Türetilmiş sınıfın nesnesinin oluşturulması
    BasePlusCommisionEmployee employee("John", "Kennedy", 10000, 0.13, 500);

    // Türetilmiş sınıfın fonksiyonlarının çağrılması
    employee.print();
    cout << "Earnings: " << employee.earnings() << endl;

    return 0;
}
