// https://www.spoj.com/problems/SUBMERGE/
#include<bits/stdc++.h>

using namespace std;

int timer; // Moved the timer inside the function to reset it for each test case.

void dfs(int node, int parent, vector<int>& tin, vector<int>& low, vector<int>& vis, vector<int> adj[], vector<int>& mark) {

    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;

    for (auto it: adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(it, node, tin, low, vis, adj, mark);
            low[node] = min(low[node], low[it]);

            if (low[it] >= tin[node] && parent != -1) 
                mark[node] = 1;
            child++;
        } 
        else {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1) {
        mark[node] = 1;
    }
}

int numberOfIslands(int n, vector<int> adj[]) {
    vector<int> tin(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> vis(n + 1, 0);
    vector<int> mark(n + 1, 0);

    timer = 1; // Reset the timer for each test case

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1, tin, low, vis, adj, mark);
        }
    }

    int res = accumulate(mark.begin(), mark.end(), 0);
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m, n != 0 && m != 0) {
        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << numberOfIslands(n, adj) << endl;
    }

    return 0;
}
