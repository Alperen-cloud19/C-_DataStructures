#include <iostream>
using namespace std;

int main()
{
    // Declares an array of five integers
    //int numbers[5];

    // Declare an array of 10 strings
    string names[10];

    // Initializes the array
    int numbers[] = {1, 2, 3, 4, 5};

    // Brace initialization
    //int numbers[] {1, 2, 3, 4, 5}

    // Reads the first element
    int first_number = numbers[0];

    // Modifies the third element
    numbers[2] = 19;

    cout << "The first and third number are: " << first_number << " and " << numbers[2] << endl;

    // Iterates over the number array using a for loop
    for (int i = 0; i < 5; ++i)
    {
        cout << "Element at index : " << i << " Element : " << numbers[i] << endl;
    }

    // Iterates over the numbers array using a for-each loop
    for (int number : numbers)
    {
        cout << "Element : " << number << endl;
    }
    return 0;
}