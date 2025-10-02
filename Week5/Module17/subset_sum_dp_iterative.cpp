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
    vector<bool> dp(k + 1,false);
    dp[0] = true;

    for(int x : v) {
        for(int j = k - x;j >= 0; j--) {
            if(dp[j] && !dp[j + x]) {
                dp[j + x] = true;
            }
            cnt++;
        }
    }

    cout << (dp[k] ? "YES" : "NO") << "\n";
    cout << cnt;
    return 0;
}

