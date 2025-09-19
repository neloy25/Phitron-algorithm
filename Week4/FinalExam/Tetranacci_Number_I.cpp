#include<bits/stdc++.h>
using namespace std;

vector<int> tet;
int tetranacci(int n) {
    if(n < 2) return n;
    if(n < 4) return n - 1;

    if(tet[n] != -1) return tet[n];

    tet[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    return tet[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    tet.assign(n + 1,-1);

    cout << tetranacci(n) << endl;
    return 0;
}

