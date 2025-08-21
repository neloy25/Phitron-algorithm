#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;
vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i,int j) {
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si,int sj) {
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + dxy[i].first;
        int cj = sj + dxy[i].second;
        if(valid(ci,cj) && !visited[ci][cj]) {
            dfs(ci,cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    grid.resize(n,vector<int>(m));
    visited.assign(n,vector<int>(m,false));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int si,sj;
    cin >> si >> sj;
    dfs(si,sj);
    return 0;
}

