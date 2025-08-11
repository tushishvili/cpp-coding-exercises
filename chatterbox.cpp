#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Stores the current list of posted messages
vector<string> posted_messages;

// Stack to keep track of deleted messages for possible restore
stack<string> deleted_messages;

// Process a DELETE command: remove last message and save it for restore
void deleteLastMessage() {
    if (!posted_messages.empty()) {
        deleted_messages.push(posted_messages.back());
        posted_messages.pop_back();
    }
}

// Process a RESTORE command: restore the last deleted message if any
void restoreLastDeleted() {
    if (!deleted_messages.empty()) {
        posted_messages.push_back(deleted_messages.top());
        deleted_messages.pop();
    }
}

// Process all commands
void processCommands(int total_commands) {
    for (int i = 0; i < total_commands; ++i) {
        string command;
        cin >> command;

        if (command == "POST") {
            string message;
            cin >> message;
            posted_messages.push_back(message);
        }
        else if (command == "DELETE") {
            deleteLastMessage();
        }
        else if (command == "RESTORE") {
            restoreLastDeleted();
        }
        // Could handle invalid commands here if needed
    }
}

// Print all current posted messages separated by spaces
void printMessages() {
    for (size_t i = 0; i < posted_messages.size(); ++i) {
        cout << posted_messages[i];
        if (i + 1 < posted_messages.size()) cout << " ";
    }
    cout << "\n";
}

int main() {
    int n;  // Number of commands
    cin >> n;
    processCommands(n);
    printMessages();
    return 0;
}
