#include <iostream>
#include <vector>

using namespace std;

vector<int> subset = {};
int n = 3;

void recursiveSubsets(int);
void printSubset();

int main() {
    recursiveSubsets(0);
    
    return 0;
}

// Recursive algorithm starts with k = 0
void recursiveSubsets(int k) {
    if(k == n) {
        printSubset();
    }
    else {
        // left branch - K is not included in subset
        recursiveSubsets(k+1);

        // right branch - K is included in subset
        subset.push_back(k);
        recursiveSubsets(k+1);
        
        // Restore subset state so left branch remains untouched
        subset.pop_back();
    }
}

void printSubset(){
    cout << "{";
    for(int i=0; i<subset.size(); i++ ){
        if(i != subset.size() - 1)
            cout << subset.at(i) << ", ";
        else
            cout << subset.at(i); 

    }
     cout << "}\n";
}
