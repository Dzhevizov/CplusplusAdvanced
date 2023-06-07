#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void readMatrix(int** oMatrix, const size_t nRows)
{
    for (size_t i = 0; i < nRows; i++)
    {
        string strRow;
        getline(cin, strRow);
        istringstream iStr(strRow);
        int nNum = 0;

        oMatrix[i] = new int[10];
        for (size_t j = 0; j < 10; j++)
        {
            if (iStr >> nNum)
                oMatrix[i][j] = nNum;
            else
                oMatrix[i][j] = 0;
        }
    }
}

bool compareMatrices(int** oMatrix1, const size_t nRows1, int** oMatrix2, const size_t nRows2)
{
    if (nRows1 != nRows2)
        return false;

    for (size_t i = 0; i < nRows1; i++)
        for (size_t j = 0; j < 10; j++)
        {
            if (oMatrix1[i][j] != oMatrix2[i][j])
                return false;
        }

    return true;
}

void deleteMatrix(int** oMatrix, const size_t nRows)
{
    for (size_t i = 0; i < nRows; i++)
        delete[] oMatrix[i];

    delete[] oMatrix;
}

int main()
{
    size_t nRows1 = 0;
    cin >> nRows1;
    cin.ignore();

    int** oMatrix1 = new int* [nRows1];
    readMatrix(oMatrix1, nRows1);

    size_t nRows2 = 0;
    cin >> nRows2;
    cin.ignore();

    int** oMatrix2 = new int* [nRows2];
    readMatrix(oMatrix2, nRows2);

    if (!compareMatrices(oMatrix1, nRows1, oMatrix2, nRows2))
        cout << "not equal" << endl;
    else
        cout << "equal" << endl;

    deleteMatrix(oMatrix1, nRows1);
    deleteMatrix(oMatrix2, nRows2);

    return 0;
}
