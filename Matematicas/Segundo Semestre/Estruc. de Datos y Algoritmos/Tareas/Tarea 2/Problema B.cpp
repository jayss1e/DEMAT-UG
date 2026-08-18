#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            int key = a[i];
            int j = i - 1;

            while(j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = key;
        }

        for(int k = 0; k < n; k++)
        {
            if(k) cout << " ";
            cout << a[k];
        }
        cout << endl;
    }

    return 0;
}