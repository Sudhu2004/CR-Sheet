// https://www.spoj.com/problems/TEST/
#include <bits/stdc++.h>
using namespace std;

vector<bool> seive() {
    int n = 1e7;
    vector<bool> primes(n + 1, 1);
    primes[0] = primes[1] = 0;

    for(int i=2; i*i<=n ;i++) {
        if(primes[i] == 1) {
            for(int j = i*i ; j<=n ; j+= i) {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

vector<int> primeNums(int n, vector<bool> nums) {
    vector<int> primes;
    for(int i=0 ;i<=n ;i++) {
        if(nums[i]) primes.push_back(i);
    }

    return primes;
}
int main() {
	int t;
    cin >> t;

    // get all prime between 0 to 1e7
    vector<bool> nums = seive();
    
    while(t--) {
        int n, m;
        cin >> m >> n;
        
        // store all prime number from 0 upto sqrt(n)
        vector<int> primes = primeNums(sqrt(n), nums);
        
        // to store the range primes
        vector<bool> dummy(n - m + 1, true);

        for(auto pr : primes) {
            int firstMult = (m/pr)*pr;

            if(firstMult < m) firstMult += pr;

            for(int j = max(firstMult, pr*pr); j<=n; j += pr) {
                dummy[j - m] = false;
            }
        }

        if (m == 1) dummy[0] = false;


        for(int i = m; i<=n ;i++) {
            if(dummy[i - m]) {
                cout << i << endl;
            }
        }
        cout << endl;
    }


    return 0;
}
