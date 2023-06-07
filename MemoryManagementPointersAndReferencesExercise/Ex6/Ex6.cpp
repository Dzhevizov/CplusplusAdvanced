#include <iostream>

using namespace std;

void readMatrix(char** oMatrix, const int nRows, const int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        oMatrix[i] = new char[nCols];

        for (int j = 0; j < nCols; j++)
        {
            cin >> oMatrix[i][j];
        }
    }
}

int countMines(char** oMatrix, const int nRow, const int nCol, const int nRows, const int nCols)
{
    int nMinesCount = 0;

    if (oMatrix[nRow][nCol] == '!')
        nMinesCount++;
    if (nRow > 0)
    {
        if (nCol > 0 && oMatrix[nRow - 1][nCol - 1] == '!')
            nMinesCount++;
        if (oMatrix[nRow - 1][nCol] == '!')
            nMinesCount++;
        if (nCol < nCols - 1 && oMatrix[nRow - 1][nCol + 1] == '!')
            nMinesCount++;
    }
    if (nRow < nRows - 1)
    {
        if (nCol > 0 && oMatrix[nRow + 1][nCol - 1] == '!')
            nMinesCount++;
        if (oMatrix[nRow + 1][nCol] == '!')
            nMinesCount++;
        if (nCol < nCols - 1 && oMatrix[nRow + 1][nCol + 1] == '!')
            nMinesCount++;
    }
    if (nCol > 0 && oMatrix[nRow][nCol - 1] == '!')
        nMinesCount++;
    if (nCol < nCols - 1 && oMatrix[nRow][nCol + 1] == '!')
        nMinesCount++;

    return nMinesCount;
}

void printMatrix(int** oMatrix, const int nRows, const int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
            cout << oMatrix[i][j];

        cout << endl;
    }
        
}

void deleteMatrix(int** oMatrix, const size_t nRows)
{
    for (size_t i = 0; i < nRows; i++)
        delete[] oMatrix[i];

    delete[] oMatrix;
}

void deleteMatrix(char** oMatrix, const size_t nRows)
{
    for (size_t i = 0; i < nRows; i++)
        delete[] oMatrix[i];

    delete[] oMatrix;
}

int main()
{
    int nRows = 0, nCols = 0;
    cin >> nRows >> nCols;

    char** oMatrix = new char* [nRows];

    readMatrix(oMatrix, nRows, nCols);

    int** oOutputMatrix = new int* [nRows];

    for (int i = 0; i < nRows; i++)
    {
        oOutputMatrix[i] = new int[nCols];

        for (int j = 0; j < nCols; j++)
        {
            int nMinesCount = countMines(oMatrix, i, j, nRows, nCols);
            oOutputMatrix[i][j] = nMinesCount;
        }
    }
        
    printMatrix(oOutputMatrix, nRows, nCols);

    deleteMatrix(oMatrix, nRows);
    deleteMatrix(oOutputMatrix, nRows);

    return 0;
}
