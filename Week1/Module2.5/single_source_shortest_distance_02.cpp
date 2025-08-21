#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int shortest_path(int src,int target) {
    vector<bool> visited(adj.size(),false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    int level = 0;

    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            int par = q.front();
            q.pop();

            if(par == target) return level;
            for(int child : adj[par]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        level++;
    }
    return -1;
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

    cout << shortest_path(0,5) << endl;


    return 0;
}

