#include <iostream>
using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    long long k[200000];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    long long inicio = 0;
    long long fin = 1000000000000000000LL; // 10^18
    long long respuesta = 0;

    while (inicio <= fin) {
        long long mitad = (inicio + fin) / 2;

        long long productos = 0;
        for (int i = 0; i < n; i++) {
            productos = productos + mitad / k[i];
            if (productos >= t) {
                break;
            }
        }

        if (productos >= t) {
            respuesta = mitad;
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }

    cout << respuesta << endl;
    return 0;
}

