#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
        cin >> v[i];

    print_vec(v);

    bool swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i+1 < n; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i+1]);
                swapped = 1;
                print_vec(v);
            }
        }
    }
    return 0;
}