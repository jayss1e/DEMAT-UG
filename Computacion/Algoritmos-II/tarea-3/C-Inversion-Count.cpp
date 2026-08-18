#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;

struct BIT {
    int bit[MAX+1];

    void reset() {
        memset(bit, 0, sizeof(bit));
    }


    void update(int i) {
        for ( ; i <= MAX; i |= i + 1)
            bit[i]++;
    }

    int query(int i) {
        int res = 0;
        for ( ; i >= 0; i = (i & (i + 1)) - 1)
            res += bit[i];
        return res;
    }
} ft;

void solve() {
    int n; cin >> n;
    long long cnt = 0;
    ft.reset();

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        long long d = ft.query(MAX) - ft.query(x);
        cnt += d;
        ft.update(x);
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}