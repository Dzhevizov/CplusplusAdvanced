#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    double dNumber = 0;

    map<double, int> oNumbersOccurences;

    while (iStr >> dNumber)
    {
        oNumbersOccurences[dNumber]++;
    }

    for (pair<double, int> Element : oNumbersOccurences)
    {
        cout << Element.first << " -> " << Element.second << endl;
    }

    return 0;
}
