#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    double dCurrNum = 0;

    vector<double> oNumbers;

    while (iStr >> dCurrNum)
    {
        oNumbers.push_back(dCurrNum);
    }

    unordered_map<double, int> oOccurencesCounter;

    for (double dNumber : oNumbers)
    {
        oOccurencesCounter[dNumber]++;
    }

    unordered_map<double, int> isPrintedNumberMap;

    for (double dNumber : oNumbers)
    {
        if (isPrintedNumberMap.find(dNumber) == isPrintedNumberMap.end())
        {
            cout << dNumber << " - " << oOccurencesCounter.at(dNumber) << " times" << endl;
            isPrintedNumberMap[dNumber]++;
        }
    }

    return 0;
}
