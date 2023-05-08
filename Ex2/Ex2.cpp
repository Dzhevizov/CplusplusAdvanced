#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;


string tolower(string& strInput)
{
    string strOutput;
    for (char chLetter : strInput)
    {
        chLetter = tolower(chLetter);
        strOutput += chLetter;
    }

    return strOutput;
}

int main()
{
    string strNumbers;
    getline(cin, strNumbers);

    stringstream oNumbers(strNumbers);
    stack<int> Numbers;

    int nNumber = 0;

    while (oNumbers >> nNumber)
    {
        Numbers.push(nNumber);
    }

    string strCommand;
    getline(cin, strCommand);

    while (strCommand != "end")
    {
        stringstream oCommand(strCommand);
        string strOperation;

        oCommand >> strOperation;
        strOperation = tolower(strOperation);

        if (strOperation == "add")
        {
            int nNum1, nNum2;
            oCommand >> nNum1 >> nNum2;

            Numbers.push(nNum1);
            Numbers.push(nNum2);
        }

        else if (strOperation == "remove")
        {
            int nNum;
            oCommand >> nNum;

            if (nNum > Numbers.size())
            {
                getline(cin, strCommand);
                continue;
            }
                
            for (size_t i = 0; i < nNum; i++)
            {
                Numbers.pop();
            }
        }

        getline(cin, strCommand);
    }

    int nSum = 0;
    while (!Numbers.empty())
    {
        nSum += Numbers.top();
        Numbers.pop();
    }

    cout << nSum << endl;

    return 0;
}
