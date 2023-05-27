#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    int nNum = 0;

    set<int> oNumbers;

    while (iStr >> nNum)
    {
        oNumbers.insert(nNum);
    }

    for (auto i = oNumbers.begin(); i != oNumbers.end(); i++)
    {
        if (i == oNumbers.begin())
        {
            cout << *i;
        }
        else
        {
            cout << " <= " << *i;
        }
    }
    return 0;
}
