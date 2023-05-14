#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    stringstream oStream(strInput);
    queue <int> oInput;

    int nNumber = 0;

    while (oStream >> nNumber)
    {
        oInput.push(nNumber);
    }

    queue <int> oOutput;
    while (!oInput.empty())
    {
        int nCurrNum = oInput.front();
        if (nCurrNum % 2 == 0)
        {
            oOutput.push(nCurrNum);
        }
        oInput.pop();
    }

    while (oOutput.size() > 1)
    {
        cout << oOutput.front() << ", ";
        oOutput.pop();
    }

    cout << oOutput.front() << endl;

    return 0;
}
