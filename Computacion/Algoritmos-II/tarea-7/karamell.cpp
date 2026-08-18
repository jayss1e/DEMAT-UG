#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> pref;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(n);

    int mid = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mid += a[i];
    }

    if (mid & 1) {
        cout << -1;
        return 0;
    }
    mid >>= 1;

    bitset<100> def; def.set();
    vector<vector<bitset<100>>> dp (n, vector<bitset<100>> (mid+1, def));

    for (int i = 0; i < n; i++) {
        dp[i][0].flip();
        if (i == 0 && a[i] <= mid) {
            dp[i][a[i]] = dp[i][0];
            dp[i][a[i]].set(i);
            continue;
        }

        for (int k = 1; k <= mid; k++) {
            if (!dp[i-1][k].all())
                dp[i][k] = dp[i-1][k];
            else {
                if (k - a[i] >= 0 && !dp[i-1][k - a[i]].all()) {
                    dp[i][k] = dp[i-1][k - a[i]];
                    dp[i][k].set(i);
                }
            }
        }
    }

    if (dp[n-1][mid].all()) {
        cout << -1;
        return 0;
    }

    // priority_queue<int> qa, qb;
    vector<int> qa, qb;
    for (int i = 0; i < n; i++) {
        if (dp[n-1][mid].test(i))
            qa.push_back(-a[i]);
        else qb.push_back(-a[i]);
    }

    int sa = 0, sb = 0;
    while (!qa.empty() || !qb.empty()) {
        if (sa <= sb) {
            cout << -qa.back() << ' ';
            sa -= qa.back();
            qa.pop_back();
        }
        else {
            cout << -qb.back() << ' ';
            sb -= qb.back();
            qb.pop_back();
        }
    }

    return 0;
}