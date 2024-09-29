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


vector<int> ZValues(string str) {
    int n = str.size();

    int left = 0 ,right = 0;
    vector<int> res(n);

    for(int k=1; k<n ;k++) {
        // This is when for checking wheather the mathcing does not
        // exceed the bound (left - right);
        if(k > right) {
            left = right = k;
            while(k < n && str[right] == str[right - left]) right++;
            res[k] = right - left;
            right--;
        }
        else {

            int k1 = k - left;
            
            //when the checking does not exceed the bounding box (left - right)
            // Copying previous value
            if(res[k1] + k < right + 1) {
                res[k] = res[k1];
            }
            else {
                // new bounding box
                left = k;
                while(k < n && str[right] == str[right - left])
                    right++;
                res[k] = right - left;
                right--;
            }
        }
    }

    return res;
}

int Zalgo(string str, string pattern) {
    string news = pattern + "$" + str;
    int m = str.size();
    int n = pattern.size();
    vector<int> res = ZValues(news);
    int cnt = 0;
    for(int i = n; i< (m + n) ; i++) {
        if(res[i] == n) cnt++;
    }

    return cnt;
}
int main() {
    string str;
    string pattern;
    
    getline(cin, str);
    getline(cin, pattern);

    // cout << KMP(str, pattern) << endl;
    cout << Zalgo(str, pattern) << endl;
    return 0;
}