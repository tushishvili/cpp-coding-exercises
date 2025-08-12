#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int arraySize, testCases, number, n;
    vector<int> numbers;   // Stores the initial list of numbers
    set<int> uniqueNumbers; // Stores unique numbers for each query

    // Input size of array and number of test cases
    cin >> arraySize >> testCases;

    // Read the array elements
    for (int i = 0; i < arraySize; i++) {
        cin >> number;
        numbers.push_back(number);
    }

    // Process each test case
    for (int j = 0; j < testCases; j++) {
        cin >> n; // Number of elements to consider from the start

        auto it = numbers.begin();
        for (int i = 0; i < n; i++) {
            uniqueNumbers.insert(*it); // Insert into set (removes duplicates automatically)
            it++;
        }

        cout << uniqueNumbers.size() << endl; // Print number of unique elements
        uniqueNumbers.clear(); // Reset for the next test case
    }
}
