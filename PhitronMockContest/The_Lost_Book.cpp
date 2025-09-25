#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v[i] = val;
    }
    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
