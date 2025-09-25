#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int tmp = 1,res = 0;
        while(tmp < n) {
            res++;
            tmp *= 2;
        }
        if(tmp == n) res++;
        cout << res << endl;
    }
    return 0;
}

