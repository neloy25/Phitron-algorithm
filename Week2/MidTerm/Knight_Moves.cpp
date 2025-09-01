#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> level;
vector<pair<int,int>> dxy = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
int n, m;

bool valid(int i,int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si,int sj) {
    queue<pair<int,int>> q;
    visited[si][sj] = true;
    level[si][sj] = 0;
    q.push({si,sj});

    while(!q.empty()) {
        auto par = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int ci = par.first + dxy[i].first;
            int cj = par.second + dxy[i].second;

            if(valid(ci,cj) && !visited[ci][cj]) {
                visited[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
                q.push({ci,cj});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        visited.assign(n,vector<bool>(m,false));
        level.assign(n,vector<int>(m,-1));
        int ki,kj; cin >> ki >> kj;
        int qi,qj; cin >> qi >> qj;

        bfs(ki,kj);
        cout << level[qi][qj] << endl;
    }
    return 0;
}

