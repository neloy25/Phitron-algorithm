#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;

    vector<int> adj_list[n];

    for(int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        sort(adj_list[i].begin(),adj_list[i].end(),greater<int>());
    }
    int q;
    cin >> q;
    while(q--){
        int src; cin >> src;
        if(adj_list[src].size() == 0) {
            cout << -1 << endl;
            continue;
        }
        for(int val: adj_list[src]) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
