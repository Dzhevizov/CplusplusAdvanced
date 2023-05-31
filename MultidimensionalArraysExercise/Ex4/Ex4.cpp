#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    size_t nRows = 0, nCols = 0;
    cin >> nRows >> nCols;

    string strSnake;
    cin >> strSnake;

    queue<char> oSnake;

    for (char chLetter : strSnake)
    {
        oSnake.push(chLetter);
    }

    vector<vector<char>> oPath(nRows, vector<char>(nCols));

    for (size_t i = 0; i < nRows; i++)
    {
        if (!(i % 2))
        {
            for (size_t j = 0; j < nCols; j++)
            {
                char chCurrChar = oSnake.front();
                oSnake.pop();
                oSnake.push(chCurrChar);

                oPath[i][j] = chCurrChar;
            }
        }
        else
        {
            int j = nCols - 1;
            for (j; j >= 0; j--)
            {
                char chCurrChar = oSnake.front();
                oSnake.pop();
                oSnake.push(chCurrChar);

                oPath[i][j] = chCurrChar;
            }
        }
    }
        
    for (size_t i = 0; i < nRows; i++)
    {
        for (size_t j = 0; j < nCols; j++)
        {
            cout << oPath[i][j];
        }

        cout << endl;
    }
        
    return 0;
}
