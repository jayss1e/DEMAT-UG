#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    stack<pair<int, int>> st;

    int x;
    for (int i = 1; i < n+1; i++) {
        cin >> x;
        while (!st.empty() && st.top().second >= x)
            st.pop();
        
        if (st.empty())
            cout << 0 << ' ';
        else cout << st.top().first << ' ';

        st.push(pair<int,int>(i, x));
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--)
        solve();
    
    return 0;
}