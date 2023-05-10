#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    stringstream oInput(strInput);
    string strKid;
    queue<string> oKids;

    while (oInput >> strKid)
    {
        oKids.push(strKid);
    }

    int nToss = 0;
    cin >> nToss;

    int nCurrToss = 0;

    while (true)
    {
        nCurrToss++;

        if (oKids.size() == 1)
        {
            cout << "Last is " << oKids.front() << endl;
            break;
        }

        if (nCurrToss == nToss)
        {
            cout << "Removed " << oKids.front() << endl;
            oKids.pop();
            nCurrToss = 0;
        }
        else
        {
            string strCurrKid = oKids.front();
            oKids.pop();
            oKids.push(strCurrKid);
        }
    }
    return 0;
}
