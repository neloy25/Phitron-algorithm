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
        if(n < 3) cout << "None\n";
        else if(n == 4 || n == 7) cout << "Leapy\n";
        else if(n == 5) cout << "Jumpster\n";
        else cout << "Both\n";
    }
    return 0;
}

