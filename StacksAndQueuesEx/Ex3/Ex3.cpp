#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

int findMinimum(stack<int> oStack)
{
    int nMinNumber = INT_MAX;

    while (!oStack.empty())
    {
        int nCurrNumber = oStack.top();

        if (nCurrNumber < nMinNumber)
            nMinNumber = nCurrNumber;

        oStack.pop();
    }

    return nMinNumber;
}

int findMaximum(stack<int> oStack)
{
    int nMaxNumber = INT_MIN;

    while (!oStack.empty())
    {
        int nCurrNumber = oStack.top();

        if (nCurrNumber > nMaxNumber)
            nMaxNumber = nCurrNumber;

        oStack.pop();
    }

    return nMaxNumber;
}

int main()
{
    int nQueryCount = 0;
    cin >> nQueryCount;

    stack<int> oNumbers;
    
    for (size_t i = 0; i < nQueryCount; i++)
    {
        int nCommand = 0;
        cin >> nCommand;

        if (nCommand == 1)
        {
            int nNumber = 0;
            cin >> nNumber;

            oNumbers.push(nNumber);
        }

        else if (nCommand == 2 && !oNumbers.empty())
        {
            oNumbers.pop();
        }

        else if (nCommand == 3 && !oNumbers.empty())
        {
            cout << findMaximum(oNumbers) << endl;
        }

        else if (nCommand == 4 && !oNumbers.empty())
        {
            cout << findMinimum(oNumbers) << endl;
        }
    }

    while (oNumbers.size() > 1)
    {
        cout << oNumbers.top() << ", ";
        oNumbers.pop();
    }

    if (oNumbers.size() == 1)
    {
        cout << oNumbers.top() << endl;
    }
    
    return 0;
}
