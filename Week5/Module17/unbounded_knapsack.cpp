#include<bits/stdc++.h>
using namespace std;

vector<int> val;
vector<int> weight;

int unbounded(int i, int w) {
    if(i < 0 || w <= 0) return 0;

    if(weight[i] <= w) {
        int opt1 = unbounded(i,w - weight[i]) + val[i];
        int opt2 = unbounded(i - 1,w);
        return max(opt1,opt2);
    } else{
        return unbounded(i - 1,w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w;
    cin >> n >> w;
    val.resize(n);
    weight.resize(n);
    for(auto &x : val) cin >> x;
    for(auto &x : weight) cin >> x;
    
    cout << unbounded(n - 1, w);
    return 0;
}

