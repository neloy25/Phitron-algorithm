#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj) {
    cout << si << " " << sj << "\n";
    visited[si][sj] = true;

    for (auto [dx, dy] : dxy) {
        int ci = si + dx;
        int cj = sj + dy;
        if (valid(ci, cj) && !visited[ci][cj]) {
            dfs(ci, cj);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    dfs(si, sj);
}
