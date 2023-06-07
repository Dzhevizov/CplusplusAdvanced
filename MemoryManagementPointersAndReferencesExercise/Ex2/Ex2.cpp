#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int* removeNegative(int *oArray, int& nSize)
{
    int* oNewArray = new int[nSize];
    int nIdx = 0;

    for (int i = 0; i < nSize; i++)
    {
        if (oArray[i] > 0)
        {
            oNewArray[nIdx] = oArray[i];
            nIdx++;
        }
    }

    nSize = nIdx;
    return oNewArray;
}

int* reverseArray(int *oArray, int& nSize)
{
    int* oNewArray = new int[nSize];
    int nIdx = 0;

    for (int i = nSize - 1; i >= 0; i--)
    {
        oNewArray[nIdx] = oArray[i];
        nIdx++;
    }

    return oNewArray;
}

int main()
{
    string strInput;
    getline(cin, strInput);

    istringstream iStr(strInput);
    int* oNumbersArray = new int[20];

    int nNumber = 0, nIdx = 0;

    while (iStr >> nNumber)
    {
        oNumbersArray[nIdx] = nNumber;
        nIdx++;
    }

    int* (*p)(int*, int&);
    p = removeNegative;
    oNumbersArray = p(oNumbersArray, nIdx);

    p = reverseArray;
    oNumbersArray = p(oNumbersArray, nIdx);

    bool bIsEmpty = true;
    for (int i = 0; i < nIdx; i++)
    {
        cout << oNumbersArray[i] << ' ';
        bIsEmpty = false;
    }

    if (bIsEmpty)
        cout << "empty";

    cout << endl;

    delete[] oNumbersArray;

    return 0;
}
