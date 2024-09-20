// https://cses.fi/problemset/task/1671/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> dijkstra(int n, vector<pair<int,ll>> edges[]) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<ll> dist(n+1, 1e18);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        ll dis = it.first;
        int node = it.second;
        
        if(dis > dist[node]) continue;

        for(auto it: edges[node]) {
            int adjNode = it.first;
            ll adjWt = it.second;

            if(dis + adjWt < dist[adjNode]) {
                dist[adjNode] = dis + adjWt;
                pq.push({dis + adjWt, adjNode});
            }
        }
    }

    return dist;
}

void getShortest(int n, vector<pair<int,ll>> edges[]) {
    vector<ll> dist = dijkstra(n, edges);

    for(int i=1; i<=n ;i++) cout << dist[i] << " ";
    cout << endl;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,ll>> edges[n+1];
    for(int i=0 ;i<m ;i++) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        edges[u].push_back({v, wt});
    }

    getShortest(n, edges);
    return 0;
}