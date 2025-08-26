#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
bool cycle = false;

void dfs(int src) {
    visited[src] = true;

    for(int child : adj[src]) {
        if(visited[child] && parent[src] != child) {
            cycle = true;
            return;
        } 
        if(!visited[child]) {
            parent[child] = src;
            dfs(child);
            if(cycle) return;
        }
    }
}
 

int main()
{
    int n,e;
    cin >> n >> e;

    adj.resize(n);
    parent.resize(n,-1);
    visited.assign(adj.size(),false);

    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            if(cycle) break;
        }
    }
    if(cycle) {
        cout << "Cycle detected";
    }
    else cout << "No cycle";
    return 0;
}

