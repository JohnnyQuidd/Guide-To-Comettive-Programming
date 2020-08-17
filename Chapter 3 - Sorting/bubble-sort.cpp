#include <iostream>

using namespace std;

void bubbleSort(int*, int);
void printArray(int*, int);

int main() {
    int array[] = {1, 5, 7, 4, 2, 9, 2, 6, 3};
    int n = sizeof(array) / sizeof(array[0]);
    
    printArray(array, n);

    bubbleSort(array, n);

    printArray(array, n);

    return 0;
}

// O(n^2) time complexity 
// Worst case number of inversions is
// 1 + 2 + 3 ... + n == (1/2) * n(n-1) => O(n^2)
// O(n) space complexity
// Bubble sort is limited in swaping consecutive elements, this suboptimal O(n^2) time complexity
void bubbleSort(int* array, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(array[j] > array[j+1])
                swap(array[j], array[j+1]);
        }
    }
}

void printArray(int* array, int n) {
    for(int i=0; i<n; i++) {
        if(i!=n-1)
            cout << array[i] << ", ";
        else 
            cout << array[i] << "\n";
    }
}