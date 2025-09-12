#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;
    Edge(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
vector<long long> dis;
int n, e;

bool bellman_ford(int src) {
    dis.assign(n, LLONG_MAX);
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto ed : edge_list) {
            int a = ed.a, b = ed.b;
            long long c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }

    for (auto ed : edge_list) {
        int a = ed.a, b = ed.b;
        long long c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge_list.push_back(Edge(a, b, c));
    }

    int s; 
    cin >> s;
    s--;

    int t;
    cin >> t;

    if (!bellman_ford(s)) {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

    while (t--) {
        int d; 
        cin >> d;
        d--;
        if (dis[d] == LLONG_MAX) cout << "Not Possible\n";
        else cout << dis[d] << "\n";
    }

    return 0;
}
