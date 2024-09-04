// https://lightoj.com/problem/funny-knapsack

// Sample Input
// 3
// 1 1
// 1
// 1 1
// 2
// 3 10
// 1 2 4
// Sample Output
// Case 1: 2
// Case 2: 1
// Case 3: 8

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Reads two integers and prints their sum
vector<ll> combinationSums(vector<ll>& nums) {
    
    vector<ll> subsets;
    int n = nums.size();
    
    for(int i=0;i<(1<<n) ; i++ ) {
        ll sum = 0;
        for(int j=0 ;j<n ;j++) {
            if(i & (1<<j))
                sum += nums[j];
        }
        subsets.push_back(sum);
    }
    
    return subsets;
}

ll getAns(vector<ll>& nums1, vector<ll>& nums2, ll w) {
    vector<ll> sums1 = combinationSums(nums1);
    vector<ll> sums2 = combinationSums(nums2);
    
    sort(sums2.begin(), sums2.end());
    ll cnt = 0;
    int sumsSize = sums2.size();
   
    for(auto num: sums1) {
        if(num > w) continue;
        
        ll maxW = w - num;
        ll left = 0;
        ll right = sumsSize - 1;
        
        while(left <= right) {
            ll mid = (left + right)/2;
            if(sums2[mid] <= maxW) left = mid + 1;
            else right = mid - 1;
        }
        cnt += left;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    int T = t;
    while(t--) {
        int n;
        ll w;
        cin >> n >> w;
        vector<ll> arr(n);
        for(int i=0 ;i<n ;i++) {
            cin >> arr[i];
        }
        
        vector<ll> nums1(arr.begin(), arr.begin() + n/2);
        vector<ll> nums2(arr.begin() + n/2, arr.end());
        
        ll ans = getAns(nums1, nums2, w);
        
        cout << "Case "<< T - t << ": " << ans << endl;
    }
    
    return 0;
}

