#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q; int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(pair<int,int>(i+1,x));
    }

    pair<int, int> t;
    int last = -1; 
    while (!q.empty()) {
        t = q.front();
        q.pop();

        t.second -= m;
        if (t.second <= 0)
            last = t.first;
        else q.push(t);
    }

    cout << last;
    
    return 0;
}