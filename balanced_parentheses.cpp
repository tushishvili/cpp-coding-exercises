#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Checks if a given string has balanced (), [], {}
bool isBalanced(const string &s) {
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        // For closing brackets, check matching opening bracket
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) return false; // No matching opening bracket

            char top = st.top();
            st.pop();

            // Check if the pair matches
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    // If stack is empty, all brackets matched
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string with parentheses/brackets/braces: ";
    getline(cin, input);

    if (isBalanced(input)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
