#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, maxVotes = 0;
    string voterName;      // Voter's name
    string candidateName;  // Candidate's name
    string winner = "";    // Winner's name

    map<string, string> voterRecord; // Maps voter -> candidate
    map<string, int> voteCount;      // Maps candidate -> number of votes

    cin >> n; // Number of votes

    // Read each vote
    for (int i = 0; i < n; i++) {
        cin >> voterName >> candidateName;

        // If this voter has not voted yet
        if (voterRecord.find(voterName) == voterRecord.end()) {
            voterRecord[voterName] = candidateName; // Record their vote
            voteCount[candidateName]++;             // Increment candidate's votes
        }
        // If voter already exists, ignore (no double voting)
    }

    // Find the candidate with the most votes
    for (auto it = voteCount.begin(); it != voteCount.end(); it++) {
        if (it->second > maxVotes) {
            maxVotes = it->second;
            winner = it->first;
        }
    }

    // Output the winner's name
    cout << winner;
}
