#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    double nCurrNumber = 0;

    vector<double> oNumbers;

    while (iStr >> nCurrNumber)
    {
        oNumbers.push_back(nCurrNumber);
    }

    sort(oNumbers.begin(), oNumbers.end(), greater<double>());

    int nCounter = 0;
    unordered_set<double> oPrintedNums;

    for (double nNumber : oNumbers)
    {
        if (oPrintedNums.find(nNumber) != oPrintedNums.end())
            continue;

        cout << nNumber << " ";
        oPrintedNums.insert(nNumber);

        if (++nCounter == 3)
            break;
    }
    return 0;
}
