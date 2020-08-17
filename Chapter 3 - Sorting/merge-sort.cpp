#include <iostream>

using namespace std;

void mergeSort(int*, int, int);
void merge(int[], int, int, int); 
void printArray(int*, int);

int main() {
    int array[] = {1, 5, 7, 4, 2, 9, 2, 6, 3};
    int n = sizeof(array) / sizeof(array[0]);
    
    printArray(array, n);

    mergeSort(array, 0, n);

    printArray(array, n);

    return 0;
}


// O(n log n) Time complexity
// It is not limited in sorting consecutive elements and it is based on recursion
// Sorting subarray array[a...b] as follows:

// 1) if a == b then do nothing because array is already sorted
// 2) Calculate the position of middle element k = [(a+b) / 2]
// 3a) Recursively sort array[a...k]
// 3b) Recursively sort array[k+1...b]
// 4) Merge sorted subarrays array[a...k] & array[k+1...b] into sorted array[a...b] 

// O(n log n) is theoretical minimum for sorting algorithms that are based on comparing elements
// Other algorithms that use some other information about array elements don't have this constraint
// Such as counting sort
void mergeSort(int* arr, int leftIndex, int rightIndex) 
{ 
    if (leftIndex < rightIndex) {
        // Same as (l+r)/2, but avoids overflow for 
        // large numbers
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, leftIndex, middleIndex); 
        mergeSort(arr, middleIndex + 1, rightIndex); 
  
        merge(arr, leftIndex, middleIndex, rightIndex); 
    }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
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