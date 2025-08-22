#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> level;
int n, m;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si,int sj) {
    queue<pair<int,int>> q;
    q.push(make_pair(si,sj));
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()) {
        pair<int,int> par = q.front();
        int par_i = par.first;
        int par_j = par.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ci = par.first + dxy[i].first;
            int cj = par.second + dxy[i].second;
            if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == '.') {
                q.push(make_pair(ci,cj));
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    level.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    cout << level[2][0];
}
