#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<char> dq1;

// Function to check if dq1 contains a palindrome
bool is_palindrome() {
    int left = 0;
    int right = dq1.size() - 1;

    while (left < right) {
        if (dq1[left] != dq1[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Passed all checks → palindrome
}

int main() {
    string s;       // The main input string
    int n;          // Length of substring to check
    int result = 0; // Count of palindromic substrings
    vector<char> vc1; // Stores characters from input string

    // Read input
    cin >> s >> n;

    // Copy string characters into a vector
    for (char ch : s) {
        vc1.push_back(ch);
    }

    // Check all substrings of length n
    while (vc1.size() >= n) {
        // Take first n characters into deque
        for (auto it = vc1.begin(); it != vc1.begin() + n; it++) {
            dq1.push_back(*it);
        }

        // Remove the first character from vector for sliding window
        vc1.erase(vc1.begin());

        // Check if current substring is a palindrome
        if (is_palindrome()) {
            result++;
        }

        dq1.clear(); // Reset deque for next check
    }

    // Output the total count of palindromic substrings
    cout << result;
}