// https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>

using namespace std;

int timer = 1;
void dfs(int node, int parent,vector<int> adj[], vector<int>& tin, vector<int>& low, vector<int>& vis, vector<pair<int,int>>& bridges) {

    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;

    for(auto it: adj[node]) {
        if(it == parent) continue;
        if(!vis[it]) {
            dfs(it, node, adj, tin , low, vis, bridges);
            low[node] = min(low[it], low[node]);

            if(low[it] > tin[node]) {
                if(it <= node)
                    bridges.push_back({it, node});
                else
                    bridges.push_back({node, it});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}
void numberOfBridges(int n, vector<int> adj[]) {
    vector<int> tin(n+1);
    vector<int> low(n+1);

    vector<int> vis(n+1, 0);

    vector<pair<int,int>> bridges;
    dfs(1, -1, adj, tin, low, vis, bridges);

    sort(bridges.begin(), bridges.end());
    if(bridges.empty()) {
        cout << "Sin bloqueos" << endl;
        return;
    }
    cout << bridges.size() << endl;
    for(auto it: bridges) {
        cout << it.first << " " << it.second << endl;
    }
}
int main() {
    int t;
    cin >> t;
    int i = 1;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n+1];

        while(m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        cout << "Caso #" << i << endl;
        numberOfBridges(n, adj);
        i++;
    }

    return 0;
}