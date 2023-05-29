#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nLinesCount = 0, nElementsCount = 0;
    cin >> nLinesCount >> nElementsCount;

    vector<vector<int>> oNumbers;

    for (size_t i = 0; i < nLinesCount; i++)
    {
        vector<int> oRow;

        for (size_t j = 0; j < nElementsCount; j++)
        {
            int nNumber = 0;
            cin >> nNumber;

            oRow.push_back(nNumber);
        }

        oNumbers.push_back(oRow);
    }

    int nMod = 0;
    cin >> nMod;

    for (size_t j = 0; j < nElementsCount; j++)
    {
        int nSum = 0;

        for (size_t i = 0; i < nLinesCount; i++)
        {
            nSum += oNumbers[i][j];
        }

        nSum %= nMod;
        cout << abs(nSum) << " ";
    }

    return 0;
}
