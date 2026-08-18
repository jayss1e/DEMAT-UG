#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    long long h[1000000];
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    long long inicio = 0;
    long long fin = 1000000000LL;
    long long respuesta = 0;

    while (inicio <= fin) {
        long long mitad = (inicio + fin) / 2;

        long long madera = 0;
        for (int i = 0; i < N; i++) {
            if (h[i] > mitad) {
                madera += (h[i] - mitad);
            }
            if (madera >= M) break;
        }

        if (madera >= M) {
            respuesta = mitad;
            inicio = mitad + 1;
        } else {
            fin = mitad - 1;
        }
    }

    cout << respuesta;
    return 0;
}

