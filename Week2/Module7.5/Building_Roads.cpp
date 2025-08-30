#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int src) {
    vis[src] = true;

    for(int child: adj[src]) {
        if(!vis[child]) dfs(child);
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    adj.assign(n,{});
    vis.assign(n,false);

    for(int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    vector<pair<int,int>> res;
    for(int i = 1; i < n;i++) {
        if(!vis[i]) {
            res.push_back({i,i+1});
            dfs(i);
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size();i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}

