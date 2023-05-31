#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t nRows = 0, nCols = 0;
    cin >> nRows >> nCols;

    vector<vector<char>> oMatrix(nRows, vector<char>(nCols));

    for (size_t i = 0; i < nRows; ++i)
    {
        for (size_t j = 0; j < nCols; ++j)
        {
            cin >> oMatrix[i][j];
        }
    }

    int nSquareMatrixesCount = 0;

    for (size_t i = 0; i < nRows - 1; ++i)
    {
        for (size_t j = 0; j < nCols - 1; ++j)
        {
            if (oMatrix[i][j] == oMatrix[i][j + 1] && oMatrix[i][j]  == oMatrix[i + 1][j] && oMatrix[i][j] == oMatrix[i + 1][j + 1])
                nSquareMatrixesCount++;
        }
    }

    cout << nSquareMatrixesCount << endl;

    return 0;
}
