#include <iostream>
#include <string>
#include <queue>

using namespace std;

int getSubExpressions(string strInput)
{
    queue<char> oExpression;
    int nBracketsCount = 0;

    for (size_t i = 0; i < strInput.length(); i++)
    {
        if (strInput[i] == ')')
        {
            nBracketsCount--;
            if (!nBracketsCount)
            {
                oExpression.push(strInput[i]);
                while (!oExpression.empty())
                {
                    cout << oExpression.front();
                    oExpression.pop();
                }
                cout << endl;
                return i;
            }
        }

        else if (strInput[i] == '(')
        {
            nBracketsCount++;
            if (nBracketsCount != 1)
            {
                string strNewString;
                for (size_t j = i; j < strInput.length(); j++)
                {
                    strNewString += strInput[j];
                }
                getSubExpressions(strNewString);
            }
        }

        if (nBracketsCount >= 1)
            oExpression.push(strInput[i]);
    }
}

int main()
{
    string strInput;
    getline(cin, strInput);

    int nIndex = 0;

    while (nIndex < strInput.length())
    {
        string strNewString;
        for (size_t j = nIndex; j < strInput.length(); j++)
        {
            strNewString += strInput[j];
        }
        int nNextIndex = getSubExpressions(strNewString);
        nIndex += nNextIndex + 1;
    }

    
    return 0;
}
