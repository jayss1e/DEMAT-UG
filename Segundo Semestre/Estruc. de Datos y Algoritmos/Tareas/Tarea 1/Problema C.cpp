#include <iostream>
using namespace std;

int n, k;
string s;
long long a[300000];

bool posible(long long X) {
    int operaciones = 0;
    bool pintando = false;

    for (int i = 0; i < n; i++) {

        // Debe quedarse roja
        if (s[i] == 'R' && a[i] > X) {
            pintando = false;
            continue;
        }

        // Debe quedar azul
        if (s[i] == 'B' && a[i] > X) {
            if (!pintando) {
                operaciones++;
                pintando = true;
            }
        }
    }

    return operaciones <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        cin >> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long left = 0, right = 1000000000LL;
        long long answer = 0;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (posible(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
