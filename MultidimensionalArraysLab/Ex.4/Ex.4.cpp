#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int nMatrixSize = 0;
    cin >> nMatrixSize;

    vector<vector<int>> oMatrix(nMatrixSize, vector<int>(nMatrixSize));

    for (size_t i = 0; i < nMatrixSize; i++)
    {
        for (size_t j = 0; j < nMatrixSize; j++)
        {
            cin >> oMatrix[i][j];
        }
    }

    int nSumPrimaryDiagonal = 0;

    for (size_t i = 0; i < nMatrixSize; i++)
    {
        nSumPrimaryDiagonal += oMatrix[i][i];
    }

    int nSumSecondaryDiagonal = 0;

    for (size_t i = 0; i < nMatrixSize; i++)
    {
        nSumSecondaryDiagonal += oMatrix[i][nMatrixSize - i - 1];
    }

    cout << abs(nSumPrimaryDiagonal - nSumSecondaryDiagonal) << endl;

    return 0;
}
