#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    map<long long, pair<int,int>> mp;

    for(int i = 0; i < n; i++) {
        long long val;
        cin >> val;

        if(mp.count(val)) mp[val].second = i + 1;
        else mp[val] = {i+1,i+1};
    }

    for(auto it: mp) {
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }
    return 0;
}

