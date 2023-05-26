#include <iostream>
#include <set>

using namespace std;

int main()
{
    size_t nNumOfLines = 0;
    cin >> nNumOfLines;

    set<int> oOddSet;
    set<int> oEvenSet;

    for (size_t i = 0; i < nNumOfLines; i++)
    {
        int nNumber = 0;
        cin >> nNumber;

        if (oOddSet.find(nNumber) != oOddSet.end())
        {
            oOddSet.erase(nNumber);
            oEvenSet.insert(nNumber);
        }
        else
        {
            oOddSet.insert(nNumber);

            if (oEvenSet.find(nNumber) != oEvenSet.end())
                oEvenSet.erase(nNumber);
        }
    }

    cout << *oEvenSet.begin() << endl;

    return 0;
}
