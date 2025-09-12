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
    int n,e;
    cin >> n >> e;
    par.assign(n+1,-1);
    group_size.assign(n+1,1);
    int res = 0;
    for(int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;

        int leader1 = find(a);
        int leader2 = find(b);

        if(leader1 == leader2) {
            res++;
        } else{
            dsu_union(a,b);
        }
    }

    cout << res;
    return 0;
}
