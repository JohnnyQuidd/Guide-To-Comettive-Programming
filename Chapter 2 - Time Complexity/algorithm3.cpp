#include <iostream>
#include <vector>

using namespace std;

typedef long unsigned int lui;

int maximumSubArray(vector<int> vector);

int main() {
    vector<int> vector = {-1, 2, 4, -3, 5, 2, -5, 2};
    cout << maximumSubArray(vector) << "\n";
    
    return 0;
}

// O(n) time complexity
// O(n) space complexity
//Idea behind this algoritm is that we're adding elements that end at certaing index
// For instance sum of subelements that at index K is sum of elements that end at index (K-1) + vector.at(K)
int maximumSubArray(vector<int> vector) {
    int best = 0;
    int sum = 0;
    for(int i = 0; i < vector.size(); i++) {
        // sum of previous and current element compared to current element
        // so if we have sum as -5, and 5 as new alement, previous sum will be dismissed and 5 will be a new sum
        sum = max(sum + vector.at(i), vector.at(i));

        best = max(best, sum); 
    }
    return best;
}