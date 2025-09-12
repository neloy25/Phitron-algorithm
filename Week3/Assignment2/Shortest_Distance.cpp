#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<long long>> adj_mat;

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (adj_mat[i][k] == LLONG_MAX) continue;
            for (int j = 0; j < n; j++) {
                if (adj_mat[k][j] == LLONG_MAX) continue;
                adj_mat[i][j] = min(adj_mat[i][j],adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e;
    cin >> n >> e;
    adj_mat.assign(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) adj_mat[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--, b--;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    floyd_warshall();

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (adj_mat[x][y] == LLONG_MAX) cout << -1 << "\n";
        else cout << adj_mat[x][y] << "\n";
    }

    return 0;
}
