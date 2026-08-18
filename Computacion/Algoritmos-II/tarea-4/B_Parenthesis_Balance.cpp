#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; getline(cin, s);
    stack<char> st;

    for (char c : s) {
        if (c == ')') {
            if (st.empty() || st.top() != '(') {
                cout << "No\n";
                return;
            }
            else st.pop();
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                cout << "No\n";
                return;
            }
            else st.pop();
        }
        else st.push(c);
    }
    cout << (st.empty() ? "Yes\n" : "No\n");
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    cin.ignore();
    while (t--)
        solve();
    
    return 0;
}