#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> ReadMatrix(int nRowsCount)
{
    vector<vector<int>> oMatrix;
   
    for (size_t i = 0; i < nRowsCount; i++)
    {
        string strRow;
        getline(cin, strRow);

        istringstream iStr(strRow);

        vector<int> oRow;
        int nNum;

        while (iStr >> nNum)
        {
            oRow.push_back(nNum);
        }

        oMatrix.push_back(oRow);
    }

    return oMatrix;
}

bool CompareMatrix(int nRows1, vector<vector<int>> oMatrix1, int nRows2, vector<vector<int>> oMatrix2)
{
    if (nRows1 != nRows2)
        return false;

    if (oMatrix1[0].size() != oMatrix2[0].size())
        return false;

    for (size_t i = 0; i < nRows1; i++)
    {
        for (size_t j = 0; j < oMatrix1[0].size(); j++)
        {
            if (oMatrix1[i][j] != oMatrix2[i][j])
                return false;
        }
    }

    return true;
}

int main()
{
    int nRowsCount1 = 0;
    cin >> nRowsCount1;
    cin.ignore();

    vector<vector<int>> oMatrix1 = ReadMatrix(nRowsCount1);

    int nRowsCount2 = 0;
    cin >> nRowsCount2;
    cin.ignore();

    vector<vector<int>> oMatrix2 = ReadMatrix(nRowsCount2);

    if (!CompareMatrix(nRowsCount1, oMatrix1, nRowsCount2, oMatrix2))
        cout << "not equal" << endl;
    else
        cout << "equal" << endl;

    return 0;
}
