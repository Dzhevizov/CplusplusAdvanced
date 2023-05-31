#include <iostream>
#include <vector>

using namespace std;


int main()
{
    size_t nRows = 0, nCols = 0;
    cin >> nRows >> nCols;

    vector<vector<int>> oMatrix(nRows, vector<int>(nCols));

    for (size_t i = 0; i < nRows; ++i)
    {
        for (size_t j = 0; j < nCols; ++j)
        {
            cin >> oMatrix[i][j];
        }
    }

    int nNumToFind = 0;
    cin >> nNumToFind;

    bool isFound = false;

    for (size_t i = 0; i < nRows; ++i)
    {
        for (size_t j = 0; j < nCols; ++j)
        {
            if (oMatrix[i][j] == nNumToFind)
            {
                isFound = true;
                cout << i << " " << j << endl;
            }
        }
    }

    if (!isFound)
        cout << "not found" << endl;

    return 0;
}
