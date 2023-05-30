#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nNumRows = 0, nNumCols = 0;
    cin >> nNumRows >> nNumCols;

    vector<vector<int>> oMatrix(nNumRows, vector<int>(nNumCols));

    for (size_t i = 0; i < nNumRows; i++)
    {
        for (size_t j = 0; j < nNumCols; j++)
        {
            cin >> oMatrix[i][j];
        }
    }

    for (size_t j = 0; j < nNumCols; j++)
    {
        int nSumCol = 0;

        for (size_t i = 0; i < nNumRows; i++)
        {
            nSumCol += oMatrix[i][j];
        }

        cout << nSumCol << endl;
    }
    return 0;
}
