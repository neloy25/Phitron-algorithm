#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int x;

bool make_it(int n) {
    if(n == x) return true;
    if(n > x) return false;

    if(dp[n] != -1) return dp[n] == 1;

    bool opt1 = make_it(n * 2);
    bool opt2 = make_it(n + 3);

    if(opt1 || opt2) dp[n] = 1;
    else dp[n] = 0;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cin >> x;
        dp.assign(x + 1, -1);

        if(make_it(1)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

