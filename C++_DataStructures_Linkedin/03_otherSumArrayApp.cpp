#include <iostream>
using namespace std;

int sumArray(const int array[], size_t size)
{
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return array[0];
    }
    else
    {
        int sum = 0;
        for (size_t i = 0; i < size; ++i)
        {
            sum += array[i];
        }
        return sum;
    }
}

int main()
{
    const int array[] {1, -7, 17};
    cout << "The sum of all element this array : " << sumArray(array, size(array)) << endl;

    return 0;
}