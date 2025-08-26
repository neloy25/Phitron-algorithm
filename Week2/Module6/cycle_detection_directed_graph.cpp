#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> path;
vector<bool> visited;

bool dfs(int src) {
    visited[src] = true;
    path[src] = true;
    for(int child : adj[src]) {
        if(visited[child] && path[child]) return true;
        if(!visited[child] && dfs(child)) return true;
    }
    path[src] = false;
    return false;
}

 

int main()
{
    int n,e;
    cin >> n >> e;

    adj.resize(n);
    path.assign(n,false);
    visited.assign(adj.size(),false);

    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    bool cycle = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                cycle = true;
                break;
            }
        }
    }
    if(cycle) {
        cout << "Cycle detected";
    }
    else cout << "No cycle";
    return 0;
}

