#include <iostream>
#include <string>

using namespace std;


string toLower(string strString)
{
    for (size_t i = 0; i < strString.length(); i++)
    {
        strString[i] = tolower(strString[i]);
    }

    return strString;
}


string toUpper(string strString)
{
    for (size_t i = 0; i < strString.length(); i++)
    {
        strString[i] = toupper(strString[i]);
    }

    return strString;
}

int main()
{
    string strInput;
    getline(cin, strInput);

    string(*p)(string);
    p = toLower;
    cout << p(strInput) << endl;

    p = toUpper;
    cout << p(strInput) << endl;

    return 0;
}
