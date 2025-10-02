#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>>  dp;

int knapsack(int i,int k) {
    if(k == 0) return 1;
    if(i < 0 || k < 0) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    int opt1 = knapsack(i - 1,k - v[i]);
    int opt2 = knapsack(i - 1,k);

    dp[i][k] = opt1 + opt2;

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

    cout << knapsack(n - 1,k);
    return 0;
}

