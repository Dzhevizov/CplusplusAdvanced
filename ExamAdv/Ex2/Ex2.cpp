#include <iostream>
#include <vector>
#include <set>

using namespace std;

void readMatrix(int** oMatrix, const int nRows, const int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        oMatrix[i] = new int[nCols];

        for (int j = 0; j < nCols; j++)
        {
            cin >> oMatrix[i][j];
        }
    }
}

bool isPrime(int nNum)
{
    if (nNum < 1)
        return false;

    if (nNum == 1 || nNum == 2)
        return true;

    for (int i = 2; i < nNum; i++)
    {
        if (nNum % i == 0)
            return false;
    }

    return true;
}

int main()
{
	int nSize = 0;
	cin >> nSize;

	int** oMatrix = new int* [nSize];
	readMatrix(oMatrix, nSize, nSize);

    set<pair<int, int>> oBelowDiagNums;

    for (int i = 0; i < nSize; i++)
    {
        for (int j = 0; j < nSize; j++)
        {
            if (i > j && j > nSize - 1 - i)
                oBelowDiagNums.insert(make_pair(i, j));
        }
    }

    vector <int> oNumbers;
        
    for (auto El : oBelowDiagNums)
    {
        oNumbers.push_back(oMatrix[El.first][El.second]);
    }

    int nSum = 0;

    for (int El : oNumbers)
    {
        if (isPrime(El))
            nSum += El;
    }

    cout << nSum;

	return 0;
}
