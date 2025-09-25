#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, q;
    cin >> t >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        ll a, b = r / 2;
        ll sum = 0;
        if (l % 2)
        {
            a = (l + 1) / 2;
        }
        else {
            a = (l / 2) + 1;
            sum += (l / 2);
        }

        if (r % 2)
            sum+= ((r + 1) / 2);

        ll n = (b - a) + 1;
        sum+= (n * ((2 * a) + n - 1));
        cout << sum<< endl;
    }
    return 0;
}
