#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the longest common substring from the original string
string getString(const string &str, int startInd, int len) {
    return str.substr(startInd - len, len);
}

// Function to find the longest common substring using DP
void UsingDP(const string &s, const string &t, int &maxLength, int &startInd) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    maxLength = 0;
    startInd = -1;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (maxLength < dp[i][j]) {
                    maxLength = dp[i][j];
                    startInd = i; // 1-based index
                }
            }
        }
    }
}

int main() {
    string t;
    getline(cin, t);

    int n = t.size();
    // string s = t;
    // reverse(t.begin(), t.end());

    // int maxLength = 0; // to store the length of the longest common substring
    // int startInd = -1; // start index in the original string

    // UsingDP(s, t, maxLength, startInd);

    // cout << getString(s, startInd, maxLength) << endl;

    

    return 0;
}
