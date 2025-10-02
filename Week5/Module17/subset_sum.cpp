#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt = 0;

bool knapsack(int i,int k) {
    cnt++;
    if(k == 0) return true;
    if(i < 0 || k < 0) return false;

    bool opt1 = knapsack(i - 1,k - v[i]);
    bool opt2 = knapsack(i - 1,k);

    return opt1 || opt2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    v.resize(n);
    for(auto &x : v) cin >> x;


    cout << knapsack(n - 1,k) << " " << cnt;
    return 0;
}

