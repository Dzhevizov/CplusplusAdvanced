#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    stack <char> oOutput;

    for (char chLetter : strInput)
    {
        oOutput.push(chLetter);
    }

    while (oOutput.size())
    {
        cout << oOutput.top();
        oOutput.pop();
    }

    cout << endl;

    return 0;
}
