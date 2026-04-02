#include <iostream>
using namespace std;

template <typename T>
T calculateAverage(T a[], int size_t)
{
    T sum = 0;
    for (int i = 0; i < size_t; i++)
    {
        sum += a[i];
    }
    return double(sum / size_t);
}

int main()
{
    int arr1[] = {512, 515, 510, 520, 514};
    int averageInt = calculateAverage<int>(arr1, size(arr1));
    cout << "Average of arr1(int): " << averageInt << endl;

    cout << endl;
    cout << "------------------------------" << endl;
    cout << endl;

    float arr2[] = {3.1f, 3.2f, 3.0f, 3.3f};
    float averageFloat = calculateAverage<float>(arr2, size(arr2));
    cout << "Average of arr2(float): " << averageFloat << endl;

    return 0;
}