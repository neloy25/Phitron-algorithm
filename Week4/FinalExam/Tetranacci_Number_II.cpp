#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> tet(n + 1,-1);

    tet[0] = 0;
    tet[1] = 1;
    tet[2] = 1;
    tet[3] = 2;

    for(int i = 4; i <= n;i++) {
        tet[i] = tet[i - 1] + tet[i - 2] + tet[i - 3] + tet[i - 4];
    }

    cout << tet[n] << endl;
    return 0;
}

