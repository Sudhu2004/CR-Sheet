#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& dist, int parent) {

    for(auto it: adj[node]) {
        if(it != parent) {
            dist[it] = dist[node] + 1;
            dfs(it, adj, dist, node);
        }
    }

}
int getAns(int n, vector<vector<int>>& edges) {
    vector<int> adj[n+1];
    
    // Create adjacency list
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, 0);
    dist[1] = 0;
    dfs(1, adj, dist, -1);

    int maxDist = 0, node = 1;
    for(int i=1; i<=n ;i++) {
        if(dist[i] > maxDist) {
            maxDist = dist[i];
            node = i;
        }
    }
    for(int i=1; i<=n ;i++) dist[i] = 0;

    dist[node] = 0;
    dfs(node, adj, dist, -1);

    for(int i=1; i<=n ;i++) {
        maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    cout << getAns(n, arr) << endl;

    return 0;
}
