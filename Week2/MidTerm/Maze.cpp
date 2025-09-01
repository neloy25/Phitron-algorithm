#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> parent;
vector<pair<int,int>> dxy = {{0,1},{0,-1},{1,0},{-1,0}};
int n, m;

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj) {
    visited[si][sj] = true;
    queue<pair<int,int>> q;
    q.push({si,sj});


    while(!q.empty()) {
        auto par = q.front();
        q.pop();

        for(int i = 0; i < 4;i++) {
            int ci = par.first + dxy[i].first;
            int cj = par.second + dxy[i].second;

            if(valid(ci,cj) && !visited[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D')) {
                visited[ci][cj] = true;
                parent[ci][cj] = par;
                q.push({ci,cj});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n,vector<pair<int,int>>(m,{-1,-1}));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    pair<int,int> target;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == 'R') {
                bfs(i, j);
            } else if(grid[i][j] == 'D') {
                target = {i,j};
            }
        }
    }

    // cout << parent[target.first][target.second].first << " " << parent[target.first][target.second].second;
    while(target.first != -1 && target.second != -1) {
        if(grid[target.first][target.second] != 'R' && grid[target.first][target.second] != 'D')
            grid[target.first][target.second] = 'X';
        target = parent[target.first][target.second];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}