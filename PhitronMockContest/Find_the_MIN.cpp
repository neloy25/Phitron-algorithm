#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else
        {
            if (s.empty())
                cout << "empty\n";
            else
            {
                cout << *s.begin() << "\n";
                s.erase(s.begin());
            }
        }
    }
    return 0;
}
