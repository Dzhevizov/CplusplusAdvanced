#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    size_t nFirstSetSize, nSecondSetSize;
    cin >> nFirstSetSize >> nSecondSetSize;

    vector<int> oFirstSetVector;
    unordered_set<int> oFirstSet;
    unordered_set<int> oSecondSet;

    for (size_t i = 0; i < nFirstSetSize; i++)
    {
        int nNumber = 0;
        cin >> nNumber;

        oFirstSetVector.push_back(nNumber);
    }

    for (size_t i = 0; i < nSecondSetSize; i++)
    {
        int nNumber = 0;
        cin >> nNumber;

        oSecondSet.insert(nNumber);
    }

    for (int nNumber : oFirstSetVector)
    {
        if (oFirstSet.find(nNumber) != oFirstSet.end())
            continue;

        oFirstSet.insert(nNumber);

        if (oSecondSet.find(nNumber) == oSecondSet.end())
            continue;

        cout << nNumber << " ";
    }

    cout << endl;

    return 0;
}
