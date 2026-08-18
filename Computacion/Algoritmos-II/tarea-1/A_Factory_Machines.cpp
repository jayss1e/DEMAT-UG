#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool test(vector<ll>& machines, ll& time, ll p) {
    ll sum = 0;
    for (ll num : machines) {
        sum += time/num;
        if (sum >= p)
            return 1;
    }
    return 0;
}

void solve() {
    int n, t;
    cin >> n >> t;

    vector<ll> machines (n);
    for (int i = 0; i < n; i++)
        cin >> machines[i];

    ll l = 1, r = (1ll << 60), m;
    while (l < r) {
        m = (l + r) >> 1;

        if (test(machines, m, t))
            r = m;
        else l = m + 1;
    }
    cout << l;
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