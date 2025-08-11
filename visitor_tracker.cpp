#include <iostream>
#include <map>
using namespace std;

int main() {
    int n; // Number of entries
    string country, passport_id;

    map<string, int> countries;   // Counts how many visitors came from each country
    map<string, int> entries;     // Counts how many times each passport ID appears

    // Read the number of records
    cin >> n;

    // Process each passport entry
    for (int i = 0; i < n; i++) {
        cin >> passport_id >> country;
        entries[passport_id]++;   // Increment entry count for this passport
        countries[country]++;     // Increment visitor count for this country
    }

    // Print countries and their visitor counts
    for (auto it = countries.begin(); it != countries.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    // Print passports that entered multiple times
    cout << "Multiple entries:" << endl;
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if (it->second > 1)
            cout << it->first << endl;
    }
}
