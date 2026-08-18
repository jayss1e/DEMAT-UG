#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 < v.size())
            cout << ' ';
    }
    cout << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v (n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    print_vec(v);

    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        for ( ; j >= 0 && v[j] > key; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = key;

        print_vec(v);
    }

    return 0;
}