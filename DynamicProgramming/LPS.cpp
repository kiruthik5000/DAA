#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidInput(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), [](char c) {
        return isalnum(c) || c == '/' || c == '.' || c == ':' || c == '-';
    });
}

string longestPrefixMatch(const vector<string>& urls, const string& request) {
    string longestPrefix = "";
    for (const string& url : urls) {
        if (request.substr(0, url.length()) == url && url.length() > longestPrefix.length()) {
            longestPrefix = url;
        }
    }
    return longestPrefix;
}

int main() {
    int n;
    cout << "Enter the number of known URLs: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input

    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 1;
    }

    vector<string> urls(n);
    cout << "Enter the known URLs:" << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, urls[i]);
        if (!isValidInput(urls[i])) {
            cout << "Invalid input" << endl;
            return 1;
        }
    }

    string request;
    cout << "Enter the incoming URL: ";
    getline(cin, request);

    if (!isValidInput(request)) {
        cout << "Invalid input" << endl;
        return 1;
    }

    string longestPrefix = longestPrefixMatch(urls, request);
    if (longestPrefix.empty()) {
        cout << "No match found" << endl;
    } else {
        cout << "Longest prefix match: " << longestPrefix << endl;
    }

    return 0;
}