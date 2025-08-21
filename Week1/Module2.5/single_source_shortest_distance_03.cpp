#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> level;

void bfs(int src) {
    queue<int> q;
    q.push(src);

    visited.resize(adj.size(),false);
    level.resize(adj.size(),-1);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}


int main()
{
    int n,e;
    cin >> n >> e;
    adj.resize(n);
    for(int i = 0; i < e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    cout << level[3] << endl;

    return 0;
}

