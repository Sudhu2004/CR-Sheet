// This question was asked in DE shaw Coding test
/*
    This problem is based on trees.

    A perfect binary tree is given along with an array of distances and the number of nodes.

    **Distances:**  
    The distance between node `x` and its parent `x/2` is given by `distance[x - 2]`.  

    Each node `i` is connected to its two child nodes `2*i` and `2*i + 1`.  

    ---

    **Problem Statement:**  
    The goal is to make the binary tree "more perfect" by ensuring that the distance from the root node `1` to all leaf nodes is the same.

    To achieve this, we are only allowed to increase the distance between any two nodes.

    ---

    **Objective:**  
    Find the minimum distance increase required to make the tree a perfect tree.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int dfs(int node, int n, int& maxi, int& ans, unordered_set<int>& st, vector<int>& dp) {
    if (st.find(node) != st.end()) {
        return maxi - dp[node];
    }
    
    int left = dfs(2 * node, n, maxi, ans, st, dp);
    int right = dfs(2 * node + 1, n, maxi, ans, st, dp);
    cout << left << "," << right << endl;
    if (left == right) return left;

    int mini = min(left, right);
    int maxii = max(left, right);
    
    ans += maxii - mini;

    return  mini;
}

int getAns(int n, vector<int>& dis) {
    unordered_set<int> st;
    vector<int> dp(n + 1);

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dis[i - 2];  // Corrected indexing for distance assignment
    }

    for (int i = 4; i <= n; i += 2) {
        dp[i] += dp[i / 2];
        dp[i + 1] += dp[(i + 1) / 2];
    }

    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
        if (2 * i > n) {
            maxi = max(maxi, dp[i]);
            st.insert(i);
        }
        if ((2 * i + 1) > n) {
            maxi = max(maxi, dp[i]);
            st.insert(i);
        }
    }
    cout << endl;
    for(int i=1; i<=n; i++) {
        cout << i << " ";
    }
    cout << endl;
    int ans = 0;
    int dummy = dfs(1, n, maxi, ans, st, dp);

    return ans;
}

int main() {
    int n;
    // cin >> n;
    // vector<int> distance(n - 1);
    // for (int i = 0; i < n - 1; i++) {
    //     cin >> distance[i];
    // }
    n = 7;
    vector<int> dis = {3, 1, 2, 1, 5, 4};
    cout << getAns(n, dis) << endl;
}
