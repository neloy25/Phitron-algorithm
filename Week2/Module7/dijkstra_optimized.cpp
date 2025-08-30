#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dist;

void dijkstra(int src) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,src});
    dist[src] = 0;

    while(!q.empty()) {
        pair<int,int> par = q.top();
        q.pop();

        int par_node = par.second;
        int par_dis = par.first;

        if (par_dis > dist[par_node]) continue;


        for(pair<int,int> child: adj_list[par_node]) {
            int child_node = child.first;
            int child_dis = child.second;
            int d = par_dis + child_dis;
            if(d < dist[child_node]) {
                dist[child_node] = d;
                q.push({d,child_node});
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

