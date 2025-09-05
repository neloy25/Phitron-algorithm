#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<vector<int>> dist;
int n;

void floyd_warshall() {
    // For direct distances
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
        for(auto child: adj_list[i]) {
            dist[i][child.first] = child.second;
        }
    }

    // main fw loop
    for(int k = 0;k < n;k++) {
        for(int i = 0; i < n; i++){
            if(dist[i][k] == INT_MAX) continue;
            for(int j = 0; j < n; j++) {
                if(dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int e;
    cin >> n >> e;
    adj_list.resize(n);
    dist.assign(n,vector<int>(n,INT_MAX));
    for(int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        // adj_list[b].push_back({a,c}); // if undirected
    }

    floyd_warshall();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (dist[i][j] == INT_MAX ? -1 : dist[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}

