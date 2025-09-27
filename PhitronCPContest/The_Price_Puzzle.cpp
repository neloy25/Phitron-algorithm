#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);

    int sum = 0;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[i] = val;
        sum+= val;
    }

    vector<bool> dp(sum + 1,false);
    dp[0] = true;


    for(int i = 0; i < n; i++) {
        for(int j = sum - v[i]; j >= 0; j--) {
            if(dp[j]) dp[j + v[i]] = true;
        }
    }

    vector<int> pre(sum + 1, 0);

    for(int i = 1; i <= sum;i++) {
        pre[i] = pre[i - 1] + dp[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int l,r;
        cin >> l >> r;
        if(l > sum) {
            cout << 0 << endl;
            continue;
        }
        if(r > sum) r = sum;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}

