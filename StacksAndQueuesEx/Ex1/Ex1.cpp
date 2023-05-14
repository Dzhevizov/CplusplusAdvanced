#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

int main()
{
    int nNumbersToPushCount = 0;
    cin >> nNumbersToPushCount;

    int nNumbersToPopCount = 0;
    cin >> nNumbersToPopCount;

    int nNumberToFind = 0;
    cin >> nNumberToFind;

    stack<int> oNumbers;

    for (size_t i = 0; i < nNumbersToPushCount; i++)
    {
        int nCurrNumber = 0;
        cin >> nCurrNumber;
        oNumbers.push(nCurrNumber);
    }

    for (size_t i = 0; i < nNumbersToPopCount; i++)
    {
        if (oNumbers.empty())
        {
            break;
        }
            
        oNumbers.pop();
    }

    if (oNumbers.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    int nSmallestNumber = INT_MAX;

    while (!oNumbers.empty())
    {
        int nCurrNumber = oNumbers.top();

        if (nCurrNumber == nNumberToFind)
        {
            cout << "true" << endl;
            return 0;
        }

        if (nCurrNumber < nSmallestNumber)
        {
            nSmallestNumber = nCurrNumber;
        }

        oNumbers.pop();
    }

    cout << nSmallestNumber << endl;
    return 0;
}
