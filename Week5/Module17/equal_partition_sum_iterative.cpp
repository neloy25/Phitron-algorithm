#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k,s = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        s+=v[i];
    }
    if(s % 2) {
        cout << "NO" << endl;
        return 0;
    }
    k = s / 2;

    vector<bool> dp(k + 1,false);
    dp[0] = true;

    for(int x : v) {
        for(int j = k - x;j >= 0; j--) {
            if(dp[j] && !dp[j + x]) {
                dp[j + x] = true;
            }
        }
    }

    cout << (dp[k] ? "YES" : "NO") << "\n";
    return 0;
}

