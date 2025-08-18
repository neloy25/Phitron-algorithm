#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<vector<int>> &adj) {
    queue<int> q;
    q.push(src);

    vector<bool> visited(adj.size(),false);
    visited[src] = true;
    while(!q.empty()) {
        int f = q.front();
        cout << f << " ";
        q.pop();

        for(int val : adj[f]) {
            if(!visited[val]) {
                q.push(val);
                visited[val] = true;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0,adj);
    return 0;
}

