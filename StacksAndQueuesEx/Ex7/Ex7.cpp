#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string strInput;
    cin >> strInput;

    stack<char> oOpeningBrackets;
    bool isBalanced = true;

    for (char chSymbol : strInput)
    {
        if (chSymbol == '(' || chSymbol == '[' || chSymbol == '{')
        {
            oOpeningBrackets.push(chSymbol);
        }

        else
        {
            if (oOpeningBrackets.empty())
            {
                isBalanced = false;
                cout << "NO" << endl;
                break;
            }

            if (chSymbol == ')' && oOpeningBrackets.top() != '(')
            {
                isBalanced = false;
                cout << "NO" << endl;
                break;
            }

            if (chSymbol == ']' && oOpeningBrackets.top() != '[')
            {
                isBalanced = false;
                cout << "NO" << endl;
                break;
            }

            if (chSymbol == '}' && oOpeningBrackets.top() != '{')
            {
                isBalanced = false;
                cout << "NO" << endl;
                break;
            }

            oOpeningBrackets.pop();
        }
    }

    if (isBalanced)
    {
        cout << "YES" << endl;
    }

    return 0;
}
