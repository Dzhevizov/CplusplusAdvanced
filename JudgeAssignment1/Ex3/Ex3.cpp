#include <iostream>
#include <string>
#include <set>

using namespace std;

#define DNALength 5

int main()
{
    char chCurrChar;
    cin.sync_with_stdio(false);
    cin >> chCurrChar;
    
    string strCurrDNA;
    set<string> oDNAs;

    while (chCurrChar != '.')
    {
        strCurrDNA += chCurrChar;

        if (strCurrDNA.length() == DNALength)
        {
            if (oDNAs.find(strCurrDNA) != oDNAs.end())
            {
                oDNAs.erase(strCurrDNA);
            }

            else
            {
                oDNAs.insert(strCurrDNA);
            }

            strCurrDNA = "";
        }

        cin >> chCurrChar;
    }

    cout.sync_with_stdio(false);
    cout << *oDNAs.begin() << endl;

    return 0;
}
