#include<bits/stdc++.h>

using namespace std;

vector<int> getAns(int n, vector<vector<int>> edges, vector<vector<int>> queries) {
    vector<int> adj[n+1];

    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> edges, queries;

    for(int i=0 ; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

}