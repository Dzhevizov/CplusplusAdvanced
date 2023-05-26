#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int nUserNamesCount = 0;
    cin >> nUserNamesCount;

    unordered_set<string> oUniqueUserNames;

    for (size_t i = 0; i < nUserNamesCount; i++)
    {
        string strUserName;
        cin >> strUserName;

        if (oUniqueUserNames.find(strUserName) != oUniqueUserNames.end())
            continue;

        cout << strUserName << endl;
        oUniqueUserNames.insert(strUserName);
    }
    return 0;
}
