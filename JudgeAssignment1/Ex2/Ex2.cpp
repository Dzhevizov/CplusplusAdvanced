#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    string strText;
    getline(cin, strText);

    char arrPunctuationSigns[] = { ',','.','!','?',';' };

    for (char chSymbol : arrPunctuationSigns)
    {
        for (size_t i = 0; i < strText.length(); i++)
        {
            if (strText[i] == chSymbol)
            {
                strText[i] = ' ';
            }
        }
    }

    istringstream iStr(strText);
    string strCurrWord, strWordToCompare;
    int nMinPercent = 0; 
    int nSimilarWordsCount = 0;

    cin >> strWordToCompare >> nMinPercent;

    while (iStr >> strCurrWord)
    {
        if (strCurrWord.length() != strWordToCompare.length() || strCurrWord[0] != strWordToCompare[0])
        {
            continue;
        }

        int nSameLetters = 0;

        for (size_t i = 0; i < strCurrWord.length(); i++)
        {
            if (strCurrWord[i] == strWordToCompare[i])
            {
                nSameLetters++;
            }
        }

        double dPercentSimilarity = (double)nSameLetters * 100 / strCurrWord.length();

        if (dPercentSimilarity >= nMinPercent)
        {
            nSimilarWordsCount++;
        }
    }

    cout << nSimilarWordsCount << endl;

    return 0;
}
