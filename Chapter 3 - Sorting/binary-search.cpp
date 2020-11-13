#include <iostream>
#include <vector>

using namespace std;

void binarySearch(vector<int> &v, int x);


int main() {
    // Array has to be sorted prior to performing binary search
    vector<int> v = {1, 4, 7, 14, 25, 46, 57, 68, 79, 102};
    int x = 426;

    binarySearch(v, x);

    return 0;
}

// Performs binary search on given vector for provided value
void binarySearch(vector<int> &v, int x) {
    int a = 0, b = v.size() - 1;
    
    // a > b ? stop
    while(a <= b) {
        int k = (a+b) / 2;
        if(v.at(k) == x) {
            cout << "Found: " << x << endl;
            return;
        }
        // drop right half of array
        else if (v.at(k) > x) {
            b = k-1;
        }
        // drop left half of array
        else a = k+1;
    }

    cout << "Number " << x << " not found\n";

}