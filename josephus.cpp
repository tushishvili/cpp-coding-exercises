#include <iostream>
#include <vector>
using namespace std;

/*
    Josephus Problem Simulation
    ---------------------------
    Problem:
    - n people stand in a circle, numbered from 1 to n.
    - Starting from the first person, you count k people and eliminate the k-th person.
    - The count continues from the next person after the eliminated one.
    - This process repeats until only one person remains.

    Input format:
    n k
    Example: 7 3
    (7 people, eliminate every 3rd person)

    Output:
    The position (number) of the last remaining person.

*/

int main() {
    int n, k;
    cin >> n >> k; // Read number of people and step size

    // Initialize the circle of people numbered from 1 to n
    vector<int> people;
    for (int i = 1; i <= n; i++)
        people.push_back(i);

    // Iterator to track current position in the circle
    auto it = people.begin();

    // Continue until only one person is left
    while (people.size() > 1) {
        // Move (k-1) steps forward in the circle
        for (int i = 1; i < k; i++) {
            it++;
            if (it == people.end()) it = people.begin(); // Wrap around to start
        }

        // Erase the k-th person
        it = people.erase(it);

        // If erase() returns end(), wrap around to the beginning
        if (it == people.end()) it = people.begin();
    }

    // Output the survivor
    cout << people[0] << endl;
}
