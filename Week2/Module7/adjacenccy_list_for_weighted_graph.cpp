#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;

int main()
{
    int n,e;
    cin >> n >> e;
    adj_list.resize(n);
    for(int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }

    for(int i = 0; i < n; i++) {
        cout << i << " >> ";
        for(pair<int,int> p : adj_list[i]) {
            cout << p.first << " " << p.second << ", ";
        }
        cout << endl;
    }
    return 0;
}

