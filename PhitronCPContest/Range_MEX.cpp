#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> cntidx(3, vector<int>(n + 1, 0));
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if(val == 0) cnt0++;
        else if(val == 1) cnt1++;
        else cnt2++;

        cntidx[0][i] = cnt0;
        cntidx[1][i] = cnt1;
        cntidx[2][i] = cnt2;
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        if(cntidx[0][r] - cntidx[0][l-1] == 0) cout << 0 << "\n";
        else if(cntidx[1][r] - cntidx[1][l-1] == 0) cout << 1 << "\n";
        else if(cntidx[2][r] - cntidx[2][l-1] == 0) cout << 2 << "\n";
        else cout << 3 << "\n";
    }

    return 0;
}
