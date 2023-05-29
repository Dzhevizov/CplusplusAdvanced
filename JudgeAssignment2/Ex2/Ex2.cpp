#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string strText;
    getline(cin, strText);

    string strCommand;
    cin >> strCommand;

    stack<string> oClipBoard;

    while (strCommand != "end")
    {
        if (strCommand == "copy")
        {
            int nFirstIdx = 0, nSecondIdx = 0;
            cin >> nFirstIdx >> nSecondIdx;

            int nBegin = 0, nEnd = strText.length() - 1;

            for (size_t i = nFirstIdx; i > nBegin; i--)
            {
                if (strText[i] == ' ' )
                {
                    nBegin = i + 1;
                    break;
                }
            }

            for (size_t i = nSecondIdx; i < nEnd; i++)
            {
                if (strText[i] == ' ')
                {
                    nEnd = i - 1;
                    break;
                }
            }

            string strSubString;
            for (size_t i = nBegin; i <= nEnd; i++)
            {
                strSubString += strText[i];
            }

            oClipBoard.push(strSubString);

            cin >> strCommand;
        }
        else
        {
            int nIdx = 0;
            cin >> nIdx;

            if (oClipBoard.empty())
                continue;

            string strSubString = oClipBoard.top();
            oClipBoard.pop();

            string strNewText;

            for (size_t i = 0; i < strText.length(); i++)
            {
                if (i == nIdx)
                {
                    if (strText[nIdx] == ' ')
                        strNewText += ' ';

                    for (size_t j = 0; j < strSubString.length(); j++)
                    {
                        strNewText += strSubString[j];
                    }
                }

                strNewText += strText[i];
            }

            strText = strNewText;
            cin >> strCommand;
        }
    }

    cout << strText << endl;
    return 0;
}