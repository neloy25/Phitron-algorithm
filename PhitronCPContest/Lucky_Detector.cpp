#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    for(char c : s) {
        if(c == '7')
        {
            cout << "Lucky" << endl;
            return 0;
        }
    }
    cout << "Not Lucky" << endl;
    return 0;
}

