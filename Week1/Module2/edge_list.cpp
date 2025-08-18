#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;
    pair<int,int> edge_list[e]; 
    for(int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;

        edge_list[i] = {a,b};
    }

    for(int i = 0; i < e; i++) {
        cout << edge_list[i].first << " " << edge_list[i].second << endl;
    }
    return 0;
}

