// https://cses.fi/problemset/task/1753

//Sample Test Case
// Input:   
// saippuakauppias
// pp
// Output:
// 2
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printStart(string str, string pattern) {
    int n = pattern.size();
    int m = str.size();

    
    int cnt = 0;
    int i = 0;
    while(i < m) {
        int j = 0;
        int k = i;
        if(str[i] == pattern[j]) {
            while(j < n && str[k] == pattern[j]) {
                k++;
                j++;
            } 
            if(j == n) cnt++;
        }
        i = k + 1;
    }

    cout << cnt << endl;
}
int main() {
    
    string str;
    string pattern;

    getline(cin, str);
    getline(cin, pattern);

    printStart(str, pattern);

    return 0;
}