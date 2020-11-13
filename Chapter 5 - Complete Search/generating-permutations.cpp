#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<int> permutations = {};
bool chosen[3] = {false, false, false};
int n = 3;

void recursivePermutations();
void printPermutations();

int main() {
    recursivePermutations();
    
    return 0;
}

void recursivePermutations() {
    if(permutations.size() == n) {
        printPermutations();
    }
    else {
       for(int i=0; i<n; i++) {
           // Current number is already contained in permutation
           if(chosen[i]) continue;

           // If number is not contained in permutation - take it and traverse further nodes
           chosen[i] = true;
           permutations.push_back(i);
           recursivePermutations();

           // After traversing child node free up taken number and pop it off the vector
           chosen[i] = false;
           permutations.pop_back();
       }
    }
}

void printPermutations(){
    cout << "{";
    for(int i=0; i<permutations.size(); i++ ){
        if(i != permutations.size() - 1)
            cout << permutations.at(i) << ", ";
        else
            cout << permutations.at(i); 

    }
     cout << "}\n";
}
