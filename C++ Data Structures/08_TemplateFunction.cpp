#include <iostream>
using namespace std;

template <typename T>
double calculateAverage(T a[], int length)
{
    T sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }
    return (double)sum / length;
}

int main()
{
    int arr1[] = {512, 515, 510, 520, 514};
    double averageInt = calculateAverage<int>(arr1, size(arr1));
    cout << "Average of arr1(int): " << averageInt << endl;

    cout << endl;
    cout << "------------------------------" << endl;
    cout << endl;

    float arr2[] = {3.1f, 3.2f, 3.0f, 3.3f};
    double averageFloat = calculateAverage<float>(arr2, size(arr2));
    cout << "Average of arr2(float): " << averageFloat << endl;

    return 0;
}