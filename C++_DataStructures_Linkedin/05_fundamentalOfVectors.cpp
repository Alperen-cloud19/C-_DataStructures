#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Create an empty vector of integers
    vector <int> myVector;

    // Add some elements to the end of the vector with push_back()
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(19);

    // Display the elements of the vector
    cout << "Elements in the vector: ";

    // C++11 and later: range-based for loop
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Delete some specific element: ";
    myVector.erase(myVector.begin() + 2); // Erase the element at index 2(which is 30)
    myVector.erase(myVector.begin() + 0); // Erase the element at index 0(which is 10)

    // Display the elements of the vector after deletion
    
    for (int element : myVector)
    {
        cout << element << " ";
    }
    cout << endl;
    // Accessing specific elements using classic array indexing
    cout << "First element: " << myVector[0] << endl;
    
    return 0;
}