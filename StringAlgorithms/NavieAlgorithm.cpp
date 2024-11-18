#include <bits/stdc++.h>
using namespace std;
bool isValidTitle(const string& title) {
    for (char c : title) {
        if (!isalnum(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}
string toLowerCase(const string& str) {
    string lowerStr = "";
    for(char i : str) {
        if(i != ' '){
        lowerStr += tolower(i);
        }
    }
    return lowerStr;
}

int main() {
    int n;
    cout << "Enter the number of book titles: ";
    cin >> n;
    cin.ignore();  // To clear the newline character from the input buffer

    // Check for invalid number of titles
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<string> titles(n);
    cout << "Enter the book titles:" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, titles[i]);

        // Check if the title contains only valid characters
        if (!isValidTitle(titles[i])) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }

    string pattern;
    cout << "Enter the title to search for: ";
    getline(cin, pattern);

    string lowerPattern = toLowerCase(pattern);
    vector<int> foundIndices;

    for (int i = 0; i < n; ++i) {
        if (toLowerCase(titles[i]) == lowerPattern) {
            foundIndices.push_back(i);
        }
    }

    // Output the results
    if (foundIndices.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int index : foundIndices) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
