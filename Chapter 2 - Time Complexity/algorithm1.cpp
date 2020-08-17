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

// O(n^3) time complexity
// O(n) space complexity
int maximumSubArray(vector<int> vector) {
    int best = vector.at(0);
    for(int i = 0; i < vector.size(); i++) {
        for(int j = i; j < vector.size(); j++) {
            int localBest = 0;
            for(int k = i; k <= j; k++) {
                localBest += vector.at(k);
            }
            best = max(best, localBest);
        }
    }
    return best;
}