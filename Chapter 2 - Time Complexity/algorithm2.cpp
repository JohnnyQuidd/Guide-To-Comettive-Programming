#include <iostream>
#include <vector>

using namespace std;

int maximumSubArray(vector<int> vector);

int main() {
    vector<int> vector = {-1, 2, 4, -3, 5, 2, -5, 2};
    cout << maximumSubArray(vector) << "\n";
    
    return 0;
}

// O(n^2) time complexity by removing one loop
// O(n) space complexity
int maximumSubArray(vector<int> vector) {
    int best = 0;
    for(int i = 0; i < vector.size(); i++) {
        int localBest = 0;
        for(int j = i; j < vector.size(); j++) {
            localBest += vector.at(j);
            best = max(localBest, best);
        }
    }
    return best;
}