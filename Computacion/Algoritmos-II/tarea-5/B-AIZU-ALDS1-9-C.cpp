#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct Heap {
    vector<int> arr;

    void _insert(int node) {
        if (node == 0)
            return;
        
        int parent = (node - 1) >> 1;
        if (arr[parent] < arr[node]) {
            swap(arr[parent], arr[node]);
            _insert(parent);
        }
    }

    void insert(int x) {
        arr.push_back(x);
        _insert(arr.size()-1); 
    }

    void _pop(int node) {
        int lt = 2*node + 1;
        int rt = 2*node + 2;

        int maxi = node;
        if (lt < arr.size() && arr[maxi] < arr[lt])
            maxi = lt;
        if (rt < arr.size() && arr[maxi] < arr[rt])
            maxi = rt;
        
        if (maxi != node) {
            swap(arr[node], arr[maxi]);
            _pop(maxi);
        }
    }

    int pop() {
        int ans = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        _pop(0);
        return ans;
    }
};

void solve() {
    Heap hp;

    string s; int k;
    while (1) {
        cin >> s;
        if (s == "end")
            break;
        
        if (s == "insert") {
            cin >> k;
            hp.insert(k);
            continue;
        }

        cout << hp.pop() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--)
        solve();

    return 0;
}