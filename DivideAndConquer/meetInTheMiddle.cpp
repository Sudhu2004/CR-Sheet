// https://cses.fi/problemset/task/1628/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

// this finds all possible sums in the subset
vector<ll> getAllSums(vector<ll>& arr, int l, int r) {
    int len = r - l + 1;

    vector<ll> ans;

    //since the range of the subset is 2^n - 1
    for(int i = 0; i < (1<<len) ; i++) {
        ll sum = 0;
        for(int j=0 ; j< len ;j++) {
            if((i & (1<<j))) {
                sum += arr[l + j];
            }
        }
        ans.push_back(sum);
    }

    return ans;
}
ll getCount(vector<ll>& arr, int n, ll x) {

    // divide the arr to two halfs of subset sums
    vector<ll> left = getAllSums(arr, 0, n/2 - 1);
    vector<ll> right = getAllSums(arr, n/2, n - 1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll ans = 0;

    // for(auto it: right) {
    //     cout << it << " ";
    // }
    // cout << endl;

    // if there exists x - it in right then there is a sum possible
    for(ll it: left) {

        // if does exist then lower_bound = upper_bound + 1;
        // else lower_boud == upper_bound
        auto low_iterator = lower_bound(right.begin(), right.end(), x - it);
        auto high_iterator = upper_bound(right.begin(), right.end(), x - it);
        ll start_index = low_iterator - right.begin();
        ll end_index = high_iterator - right.begin();
        
        ans += (end_index - start_index);
    }

    return ans;
}
int main() {
    int n;
    ll x;

    cin >> n >> x;

    vector<ll> arr(n);
    for(int i=0 ; i<n ;i++) {
        cin >> arr[i];
    }

    cout << getCount(arr, n, x) << endl;

    return 0;
}
