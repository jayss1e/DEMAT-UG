#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;

    priority_queue<ll> pq; ll x, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0 && !pq.empty()) {
            ans += pq.top();
            pq.pop();
            continue;
        }
        pq.push(x);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}