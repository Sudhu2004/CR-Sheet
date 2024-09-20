// https://cses.fi/problemset/task/1193/
// Thank you USACO Guide
// https://usaco.guide/problems/cses-1193-labyrinth/solution?lang=cpp
#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
typedef pair<int, int> ii;

vector<int> dx = {-1, 0, 1, 0};  // Up, Right, Down, Left
vector<int> dy = {0, 1, 0, -1};  // Up, Right, Down, Left
vector<char> stepDir = {'U', 'R', 'D', 'L'};  // Direction mapping

bool isValid(int row, int col, int n, int m) {
    return row >= 0 && col >=0 && row < n && col < m;
}

void getAns(int n, int m, vector<vector<char>>& A, pair<int, int> begin, pair<int, int> end) {
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> previousStep(n, vector<int>(m, -1));

    queue<ii> q;
    q.push(begin);
    vis[begin.f][begin.s] = true;

    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ii v = mp(u.f + dx[i], u.s + dy[i]);
            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;  // Out of bounds
            if (A[v.f][v.s] == '#') continue;  // Wall, can't go here
            if (vis[v.f][v.s]) continue;  // Already visited

            vis[v.f][v.s] = true;
            previousStep[v.f][v.s] = i;  // Store the step that led to this cell
            q.push(v);
        }
    }

    if (vis[end.f][end.s]) {
        cout << "YES" << endl;
        vector<int> steps;

        // Backtrack to reconstruct the path
        while (end != begin) {
            int p = previousStep[end.f][end.s];
            steps.push_back(p);
            // Undo the previous step to move back to the previous square
            end = mp(end.f - dx[p], end.s - dy[p]);
        }

        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (int c : steps) {
            cout << stepDir[c];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> A(n, vector<char>(m));
    pair<int, int> begin, end;

    // Input processing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                begin = mp(i, j);
            } else if (A[i][j] == 'B') {
                end = mp(i, j);
            }
        }
    }

    getAns(n, m, A, begin, end);

    return 0;
}
