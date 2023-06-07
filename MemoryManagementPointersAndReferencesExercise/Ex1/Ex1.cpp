#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
    string strInput;
    getline(cin, strInput);
    istringstream iStr(strInput);

    int* oNumArray = new int[100];
    int nIdx = 0, nNumber = 0;

    while (iStr >> nNumber)
    {
        oNumArray[nIdx] = nNumber;
        nIdx++;
    }

    for (int i = 0; i < nIdx / 2; i++)
    {
        cout << oNumArray[i] + oNumArray[nIdx - 1 - i] << ' ';
    }

    if (nIdx % 2)
        cout << oNumArray[(nIdx - 1) / 2] << endl;
    else
        cout << endl;

    delete[] oNumArray;

    return 0;
}
