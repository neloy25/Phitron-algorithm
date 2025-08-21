#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<bool,int>> visited;

int shortest_path(int src,int target) {
    visited.resize(adj.size(),{false,0});
    queue<int> q;
    q.push(src);
    visited[src] = {true,1};

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        for(int val : adj[f]) {
            if(!visited[val].first) {
                q.push(val);
                visited[val].first = true;
                visited[val].second = visited[f].second + 1;
            }
        }
    }

    return visited[target].second;
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

