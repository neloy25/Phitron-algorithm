#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(k + 1,0);
    dp[0] = 1;

    for(int x : v) {
        for(int j = k - x;j >= 0; j--) {
            if(dp[j]) {
                dp[j + x]++;
            }
        }
    }

    cout << dp[k];
    return 0;
}

