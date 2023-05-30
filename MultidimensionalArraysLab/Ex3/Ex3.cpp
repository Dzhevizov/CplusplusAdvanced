#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nMatrixSize = 0;
    cin >> nMatrixSize;

    vector<vector<char>> oMatrix(nMatrixSize, vector<char>(nMatrixSize));

    for (size_t i = 0; i < nMatrixSize; i++)
    {
        for (size_t j = 0; j < nMatrixSize; j++)
        {
            cin >> oMatrix[i][j];
        }
    }

    char chSearchedSymbol;
    cin >> chSearchedSymbol;

    for (size_t i = 0; i < nMatrixSize; i++)
    {
        for (size_t j = 0; j < nMatrixSize; j++)
        {
            if (oMatrix[i][j] == chSearchedSymbol)
            {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    cout << chSearchedSymbol << " does not occur in the matrix" << endl;
    return 0;
}
