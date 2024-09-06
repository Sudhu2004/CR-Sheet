#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int KMP(string str, string pattern) {

    int n = str.size();
    int m= pattern.size();

    vector<int> lps(m, 0);

    int prevLPS = 0, i = 1;
    while( i < m ) {
        if(pattern[prevLPS] == pattern[i]) {
            prevLPS++;
            lps[i] = prevLPS;
            i++;
        }
        else if(prevLPS == 0) {
            lps[i] = 0;
            i++;
        }
        else {
            prevLPS = lps[prevLPS - 1];
        }
    }
    // for(auto it: lps) cout << it << " ";
    // cout << endl;
    int cnt = 0;
    i = 0;
    int j = 0;
    while(i<n) {
        if(str[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if(j == 0) i++;
            else {
                j = lps[j-1];
            }
        }
        if(j == m) {
            cnt++;
            j = lps[j-1];
        }
    }

    return cnt;
}

int main() {
    string str;
    string pattern;
    
    getline(cin, str);
    getline(cin, pattern);

    cout << KMP(str, pattern) << endl;

    return 0;
}