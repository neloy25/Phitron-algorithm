#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        stack<char> st;

        for(char c : s) {
            if(!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        cout << st.size() << "\n";
    }
    return 0;
}
