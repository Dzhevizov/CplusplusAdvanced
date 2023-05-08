#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    stringstream oInput(strInput);

    stack<int> oNumbers;
    stack<string> oSigns;
    int nSum = 0;

    string strCurrElement;

    while (oInput >> strCurrElement)
    {
        if (strCurrElement == "+" || strCurrElement == "-")
        {
            oSigns.push(strCurrElement);
        }

        else
        {
            oNumbers.push(stoi(strCurrElement));
        }
    }

    while (!oSigns.empty())
    {
        strCurrElement = oSigns.top();

        if (strCurrElement == "+")
        {
            nSum += oNumbers.top();
            oNumbers.pop();
        }

        else
        {
            nSum -= oNumbers.top();
            oNumbers.pop();
        }

        oSigns.pop();
    }

    nSum += oNumbers.top();

    cout << nSum << endl;

    return 0;
}
