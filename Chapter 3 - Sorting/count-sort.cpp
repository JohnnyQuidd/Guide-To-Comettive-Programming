#include <iostream>
#include <string.h>

#define RANGE 255
using namespace std;

void countSort(char*, int);
void printArray(char*, int);

int main() {
    char array[] = "somerandomword";
    int n = sizeof(array) / sizeof(array[0]);
    
    countSort(array, n);

    cout << array;

    return 0;
}
// O(n) Time complexity, however it can only be used when array elements are within certain range
// For instance characters in a sentence. Not every element from given range has to be present.
// Algorithm creates a bookkeeping array
void countSort(char* arr, int n) {
    // The output character array  
    // that will have sorted arr  
    char output[strlen(arr)];  
  
    // Create a count array to store count of individual  
    // characters and initialize count array as 0  
    int count[RANGE + 1], i;  
    memset(count, 0, sizeof(count));  
  
    // Store count of each character  
    for(i = 0; arr[i]; ++i)  
        ++count[arr[i]];  
  
    // Change count[i] so that count[i] now contains actual  
    // position of this character in output array  
    for (i = 1; i <= RANGE; ++i)  
        count[i] += count[i-1];  
  
    // Build the output character array  
    for (i = 0; arr[i]; ++i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  

    // Store sorted characters in array
    for (i = 0; arr[i]; ++i)  
        arr[i] = output[i]; 
}