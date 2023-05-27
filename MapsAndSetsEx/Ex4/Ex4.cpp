#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    string strCurrWord;

    set<string> oUniqueSmallWords;

    while (iStr >> strCurrWord)
    {
        if (strCurrWord.length() >= 5)
            continue;

        transform(strCurrWord.begin(), strCurrWord.end(), strCurrWord.begin(), [](unsigned char c) {return tolower(c); });

        oUniqueSmallWords.insert(strCurrWord);
    }

    vector<string> oWordsForPrinting;

    for (string strWord : oUniqueSmallWords)
    {
        oWordsForPrinting.push_back(strWord);
    }

    for (size_t i = 0; i < oWordsForPrinting.size(); i++)
    {
        if (i < oWordsForPrinting.size() - 1)
            cout << oWordsForPrinting[i] << ", ";
        else
            cout << oWordsForPrinting[i] << endl;
    }

    return 0;
}
