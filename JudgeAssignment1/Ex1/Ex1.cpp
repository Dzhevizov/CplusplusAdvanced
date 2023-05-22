#include <iostream>
#include <string>

using namespace std;


int convertInDecimal(const string& strColour)
{
    int nMultyplier = 16;
    int nSum = 0;
    for (char chSymbol : strColour)
    {
        switch (chSymbol)
        {
        case '0': chSymbol = 0; break;
        case '1': chSymbol = 1; break;
        case '2': chSymbol = 2; break;
        case '3': chSymbol = 3; break;
        case '4': chSymbol = 4; break;
        case '5': chSymbol = 5; break;
        case '6': chSymbol = 6; break;
        case '7': chSymbol = 7; break;
        case '8': chSymbol = 8; break;
        case '9': chSymbol = 9; break;
        case 'a': chSymbol = 10; break;
        case 'b': chSymbol = 11; break;
        case 'c': chSymbol = 12; break;
        case 'd': chSymbol = 13; break;
        case 'e': chSymbol = 14; break;
        case 'f': chSymbol = 15; break;
        }

        nSum += chSymbol * nMultyplier;
        nMultyplier /= 16;
    }

    return nSum;
}


char converDecimalInHex(int nNum)
{
    char chSymbol = 0;

    switch (nNum)
    {
    case 0: chSymbol = '0'; break;
    case 1: chSymbol = '1'; break;
    case 2: chSymbol = '2'; break;
    case 3: chSymbol = '3'; break;
    case 4: chSymbol = '4'; break;
    case 5: chSymbol = '5'; break;
    case 6: chSymbol = '6'; break;
    case 7: chSymbol = '7'; break;
    case 8: chSymbol = '8'; break;
    case 9: chSymbol = '9'; break;
    case 10: chSymbol = 'a'; break;
    case 11: chSymbol = 'b'; break;
    case 12: chSymbol = 'c'; break;
    case 13: chSymbol = 'd'; break;
    case 14: chSymbol = 'e'; break;
    case 15: chSymbol = 'f'; break;
    }

    return chSymbol;
}


string findAverageColour(const string& strColour1, const string& strColour2)
{
    int nColour1 = convertInDecimal(strColour1);
    int nColour2 = convertInDecimal(strColour2);

    int nAverage = (nColour1 + nColour2) / 2;

    int nFirstNumber = nAverage / 16;
    int nSecondNumber = nAverage % 16;

    char chSymbol1 = converDecimalInHex(nFirstNumber);
    char chSymbol2 = converDecimalInHex(nSecondNumber);

    string strAverageColour;
    strAverageColour += chSymbol1; strAverageColour += chSymbol2;

    return strAverageColour;
}

int main()
{
    string strColour1, strColour2;
    cin >> strColour1 >> strColour2;

    string strRed1, strGreen1, strBlue1;
    string strRed2, strGreen2, strBlue2;

    strRed1 += strColour1[1]; strRed1 += strColour1[2];
    strGreen1 += strColour1[3]; strGreen1 += strColour1[4];
    strBlue1 += strColour1[5]; strBlue1+= strColour1[6];

    strRed2 += strColour2[1]; strRed2 += strColour2[2];
    strGreen2 += strColour2[3]; strGreen2 += strColour2[4];
    strBlue2 += strColour2[5]; strBlue2 += strColour2[6];

    string strAvgRed, strAvgGreen, strAvgBlue;

    strAvgRed = findAverageColour(strRed1, strRed2);
    strAvgGreen = findAverageColour(strGreen1, strGreen2);
    strAvgBlue = findAverageColour(strBlue1, strBlue2);

    string strNewColour;
    strNewColour = "#" + strAvgRed + strAvgGreen + strAvgBlue;

    cout << strNewColour << endl;

    return 0;
}
