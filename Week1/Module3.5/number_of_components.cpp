#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> visited;

void dfs(int src) {
    cout << src << " ";
    visited[src] = true;

    for (int neighbor : adj_list[src]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    adj_list.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            cout << endl;
            count++;
        }
    }

    cout << endl << count;
    return 0;
}
