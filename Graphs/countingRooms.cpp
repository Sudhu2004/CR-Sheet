// https://cses.fi/problemset/task/1192

// Same as number of Islands Problem
#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m) {
    return row >=0 && col >= 0 && row < n && col < m;
}
void bfs(int r, int c, int n, int m, vector<vector<int>>& vis, 
    vector<vector<int>>& floors, vector<int> drow, vector<int> dcol) {
    
    queue<pair<int,int>> q;
    q.push({r, c});
    vis[r][c] = 1;

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int row = it.first;
        int col = it.second;

        for(int i=0 ;i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(isValid(nrow, ncol, n, m)) {
                if(floors[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}
int getNumberOfRooms(int n, int m, vector<vector<int>>& floors) {
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    for(int i=0 ;i<n; i++) {
        for(int j=0; j<m ;j++) {
            if(vis[i][j] == 0 && floors[i][j] == 1) {
                // cout << "ENTERED at " << i+1 << " " << j+1 << endl;
                cnt++;
                bfs(i, j, n, m, vis, floors,drow, dcol);
            }
        }
    }

    return cnt;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> floors(n, vector<int>(m, 0));

    for(int i=0 ;i<n ;i++) {
        for(int j =0 ;j<m ;j++) {
            char ch ;
            cin >> ch;
            if(ch == '#')
                floors[i][j] = 0;
            else
                floors[i][j] = 1;
        }
    }

    // for(int i=0 ;i<n ;i++) {
    //     for(int j=0 ;j<m ;j++) {
    //         cout << floors[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << getNumberOfRooms(n, m, floors) << endl;

    return 0;
}