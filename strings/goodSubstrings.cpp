#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

int main() {
    string str, che;
    cin >> str >> che;
    int k;
    cin >> k;

    int n = str.size();
    vector<pair<ULL, ULL>> pairs;

    for(int i = 0; i<n ;i++) {
        ULL h1 = 5381, h2 = 0;
        int cnt = 0;

        for(int j=i; j<n; j++) {
            if(che[str[j] - 'a'] == '0') cnt++;
            if(cnt > k) break;

            h1 = h1 * 33ull + str[j];
            h2 = h2 * 131ull + str[j];
            pairs.push_back({h1, h2});
        }
    }

    sort(pairs.begin(), pairs.end());

    int uniqueCnt = unique(pairs.begin(), pairs.end()) - pairs.begin();
    cout << uniqueCnt << endl;
    return 0;
}