#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);
    
    for (size_t i = 0; i < strInput.length(); i++)
    {
        if (ispunct(strInput[i]))
            strInput[i] = ' ';
    }

    istringstream iStr(strInput);
    set<string> oWords;
    string strWord;

    while (iStr >> strWord)
    {
        oWords.insert(strWord);
    }

    char chCurrChar;
    cin >> chCurrChar;
    
    while (chCurrChar != '.')
    {
        for (string strCurrWord : oWords)
        {
            for (char chChar : strCurrWord)
            {
                if (chChar == tolower(chCurrChar) || chChar == toupper(chCurrChar))
                {
                    cout << strCurrWord << ' ';
                    break;
                }
            }
        }

        cout << endl;
        cin >> chCurrChar;
    }
    return 0;
}
