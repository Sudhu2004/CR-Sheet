#include<bits/stdc++.h>
using namespace std;

class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0 ;i<=n ;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findP(int node) {
        if(node == parent[node]) {
            return node;
        }

        return parent[node] = findP(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findP(u);
        int ulp_v = findP(v);

        if(ulp_v == ulp_u) return;

        if(size[ulp_u] <= size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void getAns(int n, vector<vector<int>>& edges) {
    DisJointSet ds(n);
    vector<pair<int,int>> extra_edges; // To store extra edges
    int extra = 0;

    // Union-Find with extra edge detection
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];

        if(ds.findP(u) == ds.findP(v)) {
            extra++; 
            extra_edges.push_back({u, v}); // Store the extra edge
        }
        else {
            ds.UnionBySize(u, v);
        }
    }

    // Find unique components (leaders/parents)
    unordered_set<int> parents;
    for(int i=1; i<=n ;i++) {
        parents.insert(ds.findP(i));
    }

    int num_components = parents.size(); // Number of connected components

    // If we have extra edges to connect disconnected components
    if(extra_edges.size() >= num_components - 1) {
        cout << num_components - 1 << endl; // Number of edges needed to connect components
        
        auto it = extra_edges.begin();
        auto comp_iter = parents.begin();
        int prev = *comp_iter;
        comp_iter++;
        
        // Use the extra edges to connect components
        while(comp_iter != parents.end()) {
            int next = *comp_iter;
            cout << it->first << " " << it->second << " " << prev << " " << next << endl;
            prev = next;
            it++;
            comp_iter++;
        }
    } else {
        cout << "Not enough extra edges to connect all components." << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;

    for(int i=0 ;i<n-1 ;i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }   

    getAns(n, edges);

    return 0;
}
