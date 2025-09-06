#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<ll,ll>>> adj_list;
vector<ll> dist;
vector<ll> parent;

const long long INF = 1e18;

void dijkstra(ll src) {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,src});
    dist[src] = 0;

    while(!q.empty()) {
        pair<ll,ll> par = q.top();
        q.pop();

        ll par_node = par.second;
        ll par_dis = par.first;

        if (par_dis > dist[par_node]) continue;


        for(pair<ll,ll> child: adj_list[par_node]) {
            ll child_node = child.first;
            ll child_dis = child.second;
            ll d = par_dis + child_dis;
            if(d < dist[child_node]) {
                dist[child_node] = d;
                q.push({d,child_node});
                parent[child_node] = par_node;
            }
        }
    }
}

int main()
{
    ll n,e;
    cin >> n >> e;
    adj_list.resize(n);
    dist.assign(n,INF);
    parent.assign(n,-1);
    for(ll i = 0; i < e; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    dijkstra(0);
    int node = n - 1;
    if(dist[node] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> res;
    while(node != -1) {
        res.push_back(node + 1);
        node = parent[node];
    }
    reverse(res.begin(),res.end());
    for(int val : res) {
        cout << val << " ";
    }
    return 0;
}

