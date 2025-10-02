#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>>  dp;
int cnt = 0;

bool knapsack(int i,int k) {
    cnt++;
    if(k == 0) return true;
    if(i < 0 || k < 0) return false;

    if(dp[i][k] != -1) return dp[i][k] == 1;

    bool opt1 = knapsack(i - 1,k - v[i]);
    bool opt2 = knapsack(i - 1,k);

    dp[i][k] = (opt1 || opt2) ? 1 : 0;

    return dp[i][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp.assign(n,vector<int>(k + 1,-1));

    cout << knapsack(n - 1,k) << " " << cnt;
    return 0;
}

