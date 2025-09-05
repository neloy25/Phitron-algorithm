#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj_mat;

void floyd_warshall() {
    for(int k = 0;k < n;k++) {
        for(int i = 0; i < n; i++){
            if(adj_mat[i][k] == INT_MAX) continue;
            for(int j = 0; j < n; j++) {
                if(adj_mat[k][j] == INT_MAX) continue;
                adj_mat[i][j] = min(adj_mat[i][j],adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main()
{
    int e;
    cin >> n >> e;
    adj_mat.assign(n,vector<int>(n,INT_MAX));
    for(int i = 0; i < n; i++) adj_mat[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
        // adj_mat[b][a] = min(adj_mat[b][a], c); //if undirected
    }

    floyd_warshall();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (adj_mat[i][j] == INT_MAX ? -1 : adj_mat[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}

