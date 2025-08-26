#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,-1},{0,1}};
int n, m;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj,int &count) {
    visited[si][sj] = true;
    count++;

    for (auto [dx, dy] : dxy) {
        int ci = si + dx;
        int cj = sj + dy;
        if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.') {
            dfs(ci, cj,count);
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

    int count = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                dfs(i,j,count);
                res.push_back(count);
                count = 0;
            }
        }
    }

    if (res.empty()) {
        cout << 0 << "\n";
    } else {
        sort(res.begin(), res.end());
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i] << (i+1 == res.size() ? '\n' : ' ');
        }
    }
}