#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Array
{
    // Akış (Stream) operatörünün aşırı yüklenmesi için arkadaş fonksiyon tanımı
    friend ostream& operator<<(ostream& output, const Array array);
    friend istream& operator>>(istream& input , Array& array);

    private:
        size_t size; // Dizinin boyutu
        int* ptr;    // Dinamik olarak ayrılan dizi için gösterici
    public:
        // 1. Kurucu method (Constructor)
        // Karmaşık satır içi(inline) yapı yerine anlaşılır if-else yapısı kullandık.
        explicit Array(int arraySize = 10)
        {
            if (arraySize < 0) 
            {
                throw invalid_argument("Array size must be non-negative");
            }
            size = arraySize;
            ptr = new int[size]{0}; //Bellekte yer ayır ve tüm elemanları sıfırla 
        }

        // 2. Kopya kurucu methodu (Copy Constructor)
        Array(const Array& arrayToCopy)
        {
            size = arrayToCopy.size;
            ptr = new int[size];    //Yeni bir bellek alanı açıyoruz (Derin kopyalama)

            for (size_t i = 0; i < size; ++i)
            {
                ptr[i] = arrayToCopy.ptr[i]; //Elemanları tek tek kopyala
            }
        }

        // 3. Yıkıcı method (Destructor)
        ~Array()
        {
            delete[] ptr; //Dinamik olarak ayrılan belleği serbest bırak
        }

        // 4. Atama operatörü (=) aşırı yüklemesi
        // Var olan bir nesneye yeni bir nesne atarken çalışır (örneğin: array1 = array2)

        const Array& operator=(const Array& right)
        {
            if (this != &right) //Kendine atamayı önlemek için kontrol
            {
                delete[] ptr; //Mevcut belleği serbest bırak

                size = right.size; //Yeni boyutu al
                ptr = new int[size]; //Yeni bellek alanı aç

                for (size_t i = 0; i < size; ++i)
                {
                    ptr[i] = right.ptr[i]; //Elemanları tek tek kopyala
                }
            }
            return *this; //Kendi nesnesini döndür
        }

        // 5. Eşitlik operatörünün (==) aşırı yüklenmesi
        bool operator==(const Array& right) const 
        {
            if (size != right.size) return false; //Boyutlar farklıysa eşit değiller

            for (size_t i = 0; i < size; ++i)
            {
                if (ptr[i] != right.ptr[i]) return false; //Elemanlar farklıysa eşit değiller
            }

            return true; //Tüm elemanlar eşitse eşitler
        }

        // 6. İndeks operatörünün ([]) aşırı yüklenmesi
        // Dizinin elemanlarına a[4] şeklinde erişim sağlar.
        int& operator[](int index)
        {
            if (index < 0 || static_cast<size_t>(index) >= size) 
            {
                throw out_of_range("Index out of range");
            }
            return ptr[index]; //Elemanlara referans döndür
        }
};

// Klavyeden İnput Alma (Giriş) (>>) Operatörü
istream& operator>>(istream& input , Array& array)
{
    for (size_t i = 0; i < array.size; ++i)
    {
        input >> array.ptr[i]; //Kullanıcıdan her eleman için giriş al
    }
    return input; //Giriş akışını döndür
}

// Ekrana Yazdırma (<<) Operatörü
ostream& operator<<(ostream& output , const Array array)
{
    for (size_t i = 0; i < array.size; ++i)
    {
        output << setw(5) << array.ptr[i]; //Her elemanı 5 karakter genişliğinde yazdır

        if ((i + 1) % 5 == 0) //5 eleman yazdırıldıktan sonra yeni satıra geç
        {
            output << endl;
        }
        if (array.size % 5 != 0) //Eğer toplam eleman sayısı 5'in katı değilse, son satırdan sonra yeni satır ekle
        {
            output << endl;
        }
    }
    return output; //Çıktı akışını döndür
}

int main()
{
    Array a1(10); //10 elemanlı bir Array nesnesi oluştur

    cout << "Enter 10 integers:" << endl;
    cin >> a1; //Kullanıcıdan 10 tamsayı girmesini iste

    cout << "You entered:" << endl;
    cout << a1; //Girilen değerleri ekrana yazdır

    return 0;
}