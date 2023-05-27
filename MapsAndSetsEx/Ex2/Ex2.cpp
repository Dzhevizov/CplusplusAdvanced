#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    string strCurrEl;

    vector<string> oElements;
    unordered_map<string, int> oOccurences;
    unordered_set<string> oPrintedElements;
    vector<string> oForPrinting;

    while (iStr >> strCurrEl)
    {
        transform(strCurrEl.begin(), strCurrEl.end(), strCurrEl.begin(), [](unsigned char c) {return tolower(c); });
        oElements.push_back(strCurrEl);
        oOccurences[strCurrEl]++;
    }

    for (size_t i = 0; i < oElements.size(); i++)
    {
        if (!(oOccurences[oElements[i]] % 2))
            continue;

        if (oPrintedElements.find(oElements[i]) != oPrintedElements.end())
            continue;

        oForPrinting.push_back(oElements[i]);
        
        oPrintedElements.insert(oElements[i]);
    }

    for (size_t i = 0; i < oForPrinting.size(); i++)
    {
        if (i < oForPrinting.size() - 1)
            cout << oForPrinting[i] << ", ";
        else
            cout << oForPrinting[i] << endl;
    }
    return 0;
}
