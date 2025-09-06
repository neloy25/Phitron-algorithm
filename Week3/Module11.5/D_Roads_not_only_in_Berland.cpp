#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> group_size;

int find(int node) {
    if(par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2) {
    int leader1 = find(node1);
    int leader2 = find(node2);

    if(group_size[leader1] >= group_size[leader2]) {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    } else{
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    vector<pair<int,int>> old;
    int n;
    cin >> n;
    par.assign(n+1,-1);
    group_size.assign(n+1,1);
    for(int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;

        int leader1 = find(a);
        int leader2 = find(b);

        if(leader1 == leader2) {
            old.push_back({a,b});
        } else{
            dsu_union(a,b);
        }
    }

    set<int> dis;
    for(int i = 1; i <= n; i++) {
        if(par[i] == -1) dis.insert(i);
    }

    cout << old.size() << "\n";
    auto it = dis.begin();
    for (auto [x, y] : old) {
        int u = *it; it++;
        int v = *it;
        cout << x << " " << y << " " << u << " " << v << "\n";
    }
    return 0;
}
