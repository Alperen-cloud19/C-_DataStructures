#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> myVector; // Create an empty vector of doubles

    // Add some elements to the vector and show the size and capacity after each addition
    for (int element = 0; element < 5; ++element)
    {
        myVector.push_back(element * 1.9); // Add elements to the vector
        // Display the current size and capacity of the vector
        cout << "Size: " << myVector.size() << " Capacity: " << myVector.capacity() << endl;
    }

    // Delete the last element from the vector and show new size and capacity
    myVector.pop_back(); // Remove the last element
    cout << endl;
    cout << "After pop_back() - Size: " << myVector.size() << " Capacity: " << myVector.capacity() << endl;
    
    // Delete specified element from the vector and show new size and capacity
    cout << endl;
    myVector.erase(myVector.begin() + 1); // Remove the element at 1 index
    cout << "After erase specified element - Size: " << myVector.size() <<
            " Capacity: " << myVector.capacity() << endl;
    
    // Delete all elements from the vector and show new size and capacity
    cout << endl;
    myVector.clear(); // Remove all elements from vector
    cout << "After clear all elements - Size: " << myVector.size() << " Capacity: " << myVector.capacity() << endl;
    
    return 0;
}