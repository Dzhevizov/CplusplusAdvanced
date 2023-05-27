#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSquare(int nNumber)
{
    if (nNumber < 1)
        return false;

    if (nNumber == 1)
        return true;

    for (int i = 2; i <= nNumber / 2; i++)
    {
        if (i * i == nNumber)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    int nNum = 0;

    vector<int> oNumbers;

    while (iStr >> nNum)
    {
        oNumbers.push_back(nNum);
    }

    sort(oNumbers.begin(), oNumbers.end(), greater<int>());

    for (int nNumber : oNumbers)
    {
        if (isSquare(nNumber))
        {
            cout << nNumber << " ";
        }
    }
    return 0;
}
