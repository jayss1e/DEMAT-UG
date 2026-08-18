#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool test(vector<ll>& h, ll ht, ll mini) {
    ll sum = 0;
    
    for (ll num : h) {
        sum += max(num - ht, 0ll);
        if (sum >= mini)
            return 1; 
    }
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> h (n);

    for (int i = 0; i < n; i++) 
        cin >> h[i];

    ll l = 0, r = (1ll << 30), m;
    while (l < r) {
        m = (l + r) >> 1;
        if (test(h, m, k))
            l = m + 1;
        else r = m;
    }
    cout << l - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) 
        solve();
    return 0;
}