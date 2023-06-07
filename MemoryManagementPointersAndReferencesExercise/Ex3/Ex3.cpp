#include <iostream>

using namespace std;

int main()
{
    size_t nRows = 0, nCols = 0;
    cin >> nRows >> nCols;

    int** oMatrix = new int* [nRows];

    for (size_t i = 0; i < nRows; i++)
    {
        oMatrix[i] = new int [nCols];

        for (size_t j = 0; j < nCols; j++)
            cin >> oMatrix[i][j];
    }

    size_t nNewRows = 0, nNewCols = 0;
    cin >> nNewRows >> nNewCols;

    if (nNewRows <= nRows && nNewCols <= nCols)
    {
        for (size_t i = 0; i < nNewRows; i++)
        {
            for (size_t j = 0; j < nNewCols; j++)
            {
                cout << oMatrix[i][j] << " ";
            }

            cout << endl;
        }
    }
    
    for (size_t i = 0; i < nRows; i++)
        delete[] oMatrix[i];

    delete[] oMatrix;

    return 0;
}
