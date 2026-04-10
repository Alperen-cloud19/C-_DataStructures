#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int numbers[] = {10, 15, 2, 3, 5, 7, 11, 13};
    vector<int> PrimeNumbers;

    for (int num : numbers)
    {
        if (num > 1 && isPrime(num))
        {
            PrimeNumbers.push_back(num);
        }
    }

    if (size(PrimeNumbers) == 0)
    {
        cout << "No prime numbers found in the array." << endl;
    }
    else
    {
        cout << "The prime numbers in the array are: ";
        for (int prime : PrimeNumbers)
        {
            if (prime == PrimeNumbers[size(PrimeNumbers)-1])
            {
                cout << prime; // Print the last prime number without a comma
                break; // Exit the loop after printing the last prime number
            }
            cout << prime << ", ";
            
        }
        cout << endl;
    }

    return 0;
}