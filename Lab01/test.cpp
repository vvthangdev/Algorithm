// C++ Program to demonstrate array printing using a range-based for loop

#include <iostream>

using namespace std;

// Method to print array elements
void print(const int &arr[], size_t n) {
    // Iterating over elements in the array using the range-based for loop
    for (size_t i = 0; i < n; i++) {
        // Print the elements of the array
        cout << arr[i] << " ";
    }

    // New line after printing all the elements
    cout << endl;
}

// Main driver method
int main() {
    // Declaring and initializing Integer array with custom input entries
    int a[]{ 1, 2, 3, 4 };

    // Calculate the size of the array
    size_t size = sizeof(a) / sizeof(a[0]);

    // Calling the print function to display array elements
    print(a, size);
}
