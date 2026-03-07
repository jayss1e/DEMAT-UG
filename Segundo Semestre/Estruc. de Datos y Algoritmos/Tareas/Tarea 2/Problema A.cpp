#include <iostream>
using namespace std;

void vPrintArray(int *pArr, int nSize)
{
    for(int i = 0; i < nSize; i++)
    {
        if(i > 0) cout << " ";
        cout << pArr[i];
    }
    cout << endl;
}

int main()
{
    int nN;
    cin >> nN;

    int arrA[20];

    for(int i = 0; i < nN; i++)
    {
        cin >> arrA[i];
    }

    // imprimir arreglo inicial
    vPrintArray(arrA, nN);

    // bubble sort
    for(int i = 0; i < nN - 1; i++)
    {
        for(int j = 0; j < nN - i - 1; j++)
        {
            if(arrA[j] > arrA[j + 1])
            {
                int nTemp = arrA[j];
                arrA[j] = arrA[j + 1];
                arrA[j + 1] = nTemp;

                // imprimir después de cada swap
                vPrintArray(arrA, nN);
            }
        }
    }

    return 0;
}