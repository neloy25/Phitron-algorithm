#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> level;
vector<int> parent;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj[par]) {
            if(!visited[child]) {
                visited[child] = true;
                level[child] = level[par] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<int,int>> edges;
    for(int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        edges.insert({a,b});
    }

    int q;
    cin >> q;
    while(q--) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        edges.erase({a,b});
    }

    adj.resize(n);
    visited.assign(n, false);
    level.assign(n, -1);
    parent.assign(n, -1);

    for(auto p : edges) {
        int u = p.first, v = p.second;
        adj[u].push_back(v);
        parent[v] = u;
    }

    for(int i = 0; i < n; i++) {
        if(parent[i] == -1 && !visited[i]) {
            bfs(i);
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << level[i] * 2 << " ";
    }
    cout << "\n";

    return 0;
}
