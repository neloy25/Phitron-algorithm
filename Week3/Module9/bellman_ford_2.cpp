#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int a;
    int b;
    int c;
    Edge(int a,int b,int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
vector<int> dis;
int n,e;

void bellman_ford(int src) {
    dis[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(auto ed : edge_list) {
            int a = ed.a,b = ed.b,c = ed.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]) {
                dis[b] = dis[a] + c;
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    dis.assign(n,INT_MAX);

    for(int i = 0; i < e; i++) {
        int a,b,c; 
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
        // edge_list.push_back(Edge(b,a,c)); // for undirected
    }

    bellman_ford(0);
    for(int i = 0; i < n;i++) {
        cout << dis[i] << endl;
    }
    return 0;
}

