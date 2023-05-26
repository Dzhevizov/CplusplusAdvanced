#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int nNamesCount = 0;
    cin >> nNamesCount;

    unordered_set<string> oUniqueNames;

    for (size_t i = 0; i < nNamesCount; i++)
    {
        string strName;
        cin >> strName;

        if (oUniqueNames.find(strName) != oUniqueNames.end())
            continue;

        cout << strName << endl;
        oUniqueNames.insert(strName);
    }
    return 0;
}
