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
        priority_queue<pair<int,int>> q;

        for(int i = 0; i < n;i++) {
            int val;
            cin >> val;
            q.push({val,i});
        }

        int a,b;
        a = q.top().second;
        q.pop();
        b = q.top().second;
        cout << min(a,b) << " " << max(a,b) << endl;
    }
    return 0;
}

