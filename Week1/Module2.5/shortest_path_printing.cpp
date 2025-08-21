#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> level;
vector<int> parent;

void bfs(int src) {
    queue<int> q;
    q.push(src);

    level.assign(adj.size(),-1);
    parent.assign(adj.size(),-1);
    level[src] = 0;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj[par]) {
            if(level[child] == -1) {
                q.push(child);
                level[child] = level[par] + 1;
                parent[child] = par;
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

    int src,target;
    cin >> src >> target;
    bfs(src);
    
    int node = target;

    vector<int> res;
    while(node != -1) {
        res.push_back(node);
        node = parent[node];
    }
    reverse(res.begin(),res.end());
    for(int val : res) {
        cout << val << " ";
    }
    return 0;
}

