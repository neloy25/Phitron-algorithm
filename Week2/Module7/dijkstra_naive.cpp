#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dist;

void dijkstra(int src) {
    queue<pair<int,int>> q;
    q.push({src,0});
    dist[src] = 0;

    while(!q.empty()) {
        pair<int,int> par = q.front();
        q.pop();

        for(pair<int,int> child: adj_list[par.first]) {
            int d = par.second + child.second;
            if(d < dist[child.first]) {
                dist[child.first] = d;
                q.push({child.first,d});
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    adj_list.resize(n);
    dist.assign(n,INT_MAX);
    for(int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    dijkstra(0);
    for(int i = 0; i < n;i++) {
        cout << "Min dist to " << i << " = " << dist[i] << endl;
    }
    return 0;
}

