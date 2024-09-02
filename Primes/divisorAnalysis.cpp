// https://cses.fi/problemset/task/2182
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll MOD = 1e9 + 7;

ll mul(ll x, ll y, ll modulo) {
    return ((x % modulo) * (y % modulo)) % modulo;
}

ll powers(ll x, ll p, ll modulo) {
    x = x % modulo;
    if (p == 0) return 1;
    if (p == 1) return x;
    ll z = powers(x, p / 2, modulo);
    if (p % 2 == 0) return mul(z, z, modulo);
    else return mul(mul(z, z, modulo), x, modulo);
}

ll dividing(ll x, ll y, ll modulo) {
    return mul(x, powers(y, modulo - 2, modulo), modulo);
}
// do a dry run of the test case to find cnt, sums and prod
// we will get the formula for all three once we do it..
// testcase:
// 3
// 2 2
// 3 1
// 5 2

// try it , if possible


void printAns(int n, vector<pair<int, ll>>& factors) {
    ll cnt = 1, sums = 1, product = 1;
    ll count2 = 1;

    for (int i = 0; i < n; ++i) {
        int x = factors[i].first;
        ll k = factors[i].second;

        // original
        cnt = mul(cnt, k + 1, MOD);

        // sums = prevsums * (sum of gp of current x with r = k+1)
        // sumOfGP = a^(x^(k+1) - 1)/(x - 1)   -> a = 1

        // ll sumsNum = (power(x, k + 1) - 1LL) % MOD;
        // ll sumsDen = (power(x-1, MOD - 2)) % MOD;   
        // sums = (sums * (sumsNum * sumsDen));
        ll current_num = (powers(x, k + 1, MOD) - 1 + MOD) % MOD;
        ll current_den = (x - 1 + MOD) % MOD;
        sums = mul(sums, dividing(current_num, current_den, MOD), MOD);


        // currprod = prevprod^(k + 1) * ((x ^ (sumOf(k)^prevcnt) )
        ll sum_of_k = (k * (k + 1) / 2) % (MOD - 1); // MOD-1 is used here for the exponent
        product = mul(powers(product, k + 1, MOD), powers(powers(x, sum_of_k, MOD), count2, MOD), MOD);

        // cnt  = prevCnt * (number Of Divisors Of that number)
        // for x = 3 and k = 1 => divisors = (3^0 + 3^1) <=> cnt = 2
        count2 = mul(count2, k + 1, MOD - 1);
        
    }

    cout << cnt << " " << sums << " " << product << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, ll>> factors;

    for (int i = 0; i < n; ++i) {
        int x;
        ll k;
        cin >> x >> k;
        factors.push_back({x, k});
    }

    printAns(n, factors);

    return 0;
}
