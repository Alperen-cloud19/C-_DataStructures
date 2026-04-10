#include <iostream>
#include <vector>
using namespace std;

// For some image processing application,
// we need to store some special points in the image, 
//which are represented as (x, y, w, h) coordinates.

class BoundingBox
{
    protected:
        int x, y, width, height;
    public:
        BoundingBox(int x_val, int y_val, int w_val, int h_val) : x(x_val), y(y_val), width(w_val), height(h_val)
        {
            cout << "Bounding Boxing is created..." << endl;
        }
};

int main()
{
    vector<BoundingBox> detectionObjects;

    // We allocated 100 element for avoid reallocation waste memory.
    detectionObjects.reserve(100);

    // Temporary object is copied with push_back() method
    //detectionObjects.push_back(10, 12, 50, 80);

    // emplace_back method is bringed object and structured own memory directly (more performance)
    detectionObjects.emplace_back(10, 19, 50, 50);
    detectionObjects.emplace_back(150, 80, 45, 60);

    // the number of size of detection objects show that below
    cout << "Number of detection objects : " << detectionObjects.size() << endl;
    
    return 0;
}