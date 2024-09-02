#include <bits/stdc++.h>
using namespace std;

vector<int> seive() {
    int n = 1e7;
    vector<int> primes(n + 1, 1);
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
int main() {
	int t;
    cin >> t;

    vector<int> primes = seive();
    for(int i=2 ;i<= 1e7 +1; i++) {
        primes[i] += primes[i-1];
    }
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = primes[m] - primes[n - 1 ];
        cout << ans << endl;
    }


    return 0;
}
