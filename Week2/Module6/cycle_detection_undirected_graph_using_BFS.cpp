#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;


bool bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int val : adj[par]) {
            if(!visited[val]) {
                q.push(val);
                visited[val] = true;
                parent[val] = par;
            } else{
                if(val != parent[par]) {
                    cout << val << " " << par << endl;
                    return true;
                }
            }
        }
    }
    return false;
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

    bool cycle = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(bfs(i)) {
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

