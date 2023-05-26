#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    size_t nNumOfLines = 0;
    cin >> nNumOfLines;
    cin.ignore();

    set<string> oChemicalElements;

    for (size_t i = 0; i < nNumOfLines; i++)
    {
        string strInput;
        getline(cin, strInput);

        istringstream iStr(strInput);
        string strCurrEl;

        while (iStr >> strCurrEl)
        {
            oChemicalElements.insert(strCurrEl);
        }
    }

    for (auto it = oChemicalElements.begin(); it != oChemicalElements.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
