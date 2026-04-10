#include <iostream>
using namespace std;

void sum_array(int array[], int size_array)
{
    int sum =0;

    for (int i = 0; i < size_array; i++)
    {
        sum += array[i];
    }
    cout << "The sum of all element of this array : " << sum << endl;
}

int main()
{   
    // get array size from user
    int size_array;
    cout << "Enter your array size:"; cin >> size_array;

    // create array
    int array1[size_array];

    // get array elements from user 
    for (int i = 0; i < size_array; i++)
    {
        cout << "Enter element:"; cin >> array1[i];
    }

    sum_array(array1, size_array);
    
    return 0;
}

