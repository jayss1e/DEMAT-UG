#include <iostream>
#include "forest.hpp"

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Forest f;
    int q; cin >> q;

    string s; int qt, h, p, t;
    while (q--) {
        cin >> qt;
        switch(qt) {
            case 1:
                cin >> s >> h >> p;
                f.insert(Tree(f.get_size(), h, p, s));
                cout << f.get_size() - 1 << '\n';
                break;

            case 2:
                cin >> t;
                cout << f.max_height(t) << '\n';
                break;

            case 3:
                cin >> t >> s;
                cout << f.max_height(t, s) << '\n';
                break;

            case 4:
                cout << f.type_mode() << '\n';
                break;

            case 5:
                cout << f.lex_smallest_type() << '\n';
                break;

            case 6:
                cout << f.lex_greatest_type() << '\n';
                break;
        }
    }
}