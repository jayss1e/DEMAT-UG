#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAX = 1e9;

bool test(vector<int>& penalty, int k, int maxi, bool curr) {
    bool behind = 0;

    for (int i = 0; i < penalty.size(); i++, curr = !curr) {
        // CURRENT CELL IS EXPECTED BLUE
        if (curr) {
            if (penalty[i] > maxi) {
                k -= !behind;
                behind = 1;
            }
            continue;
        }

        // CURRENT CELL IS EXPECTED RED
        if (penalty[i] > maxi)
            behind = 0;
    }

    return (k >= 0);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<bool> obj (n);
    vector<int> penalty;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        obj[i] = (c == 'B');
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        
        if (i && obj[i - 1] != obj[i])
            penalty.push_back(maxi), maxi = 0;

        maxi = max(maxi, x);
    }

    penalty.push_back(maxi);

    int l = 0, r = MAX, m;
    while (l < r) {
        m = (l + r) >> 1;

        if (test(penalty, k, m, obj[0]))
            r = m;
        else l = m + 1;
    }
    cout << l << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}