// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/disjoint-set-union/

#include <bits/stdc++.h>
using namespace std;

class DisJointSet {
public:
	vector<int> parent, size;
	DisJointSet(int n) {
		parent.resize(n+1);
		size.resize(n+1);

		for(int i=1; i<=n ;i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findP(int node) {
		if (node == parent[node])
            return node;
        return parent[node] = findP(parent[node]);
	}

	void UnionBySize(int u, int v) {
		int ulp_u = findP(u);
		int ulp_v = findP(v);
		if(ulp_u == ulp_v) return;

		if(size[ulp_v] <= size[ulp_u]) {
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		else {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
	}
};


void print(vector<int>& sizes) {
    sort(sizes.begin(), sizes.end());
	for(auto it: sizes) {
		if(it != 0) cout << it << " ";
	}
	cout << endl;
}
void getAns(int n, vector<vector<int>> edges) {
	DisJointSet ds(n+1);

	vector<int> sizes;
	for(auto it: edges) {
		int u = it[0];
		int v = it[1];
		ds.UnionBySize(u, v);
		vector<int> sizes(n+1, 0);
		
		for(int i=1 ;i<=n ;i++) {
			sizes[ds.findP(i)]++;
		}
        
		print(sizes);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges;
	while(m--) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a, b});
	}

	getAns(n, edges);

	return 0;
}
