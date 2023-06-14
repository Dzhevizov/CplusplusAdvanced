#include <iostream>
#include <vector>

using namespace std;

void readMatrix(char** oMatrix)
{
    for (size_t i = 0; i < 10; i++)
    {
        oMatrix[i] = new char[10];

        for (size_t j = 0; j < 10; j++)
        {
            cin >> oMatrix[i][j];
        }
    }
}

void findRusties(char** oMatrix, vector<pair<int, int>>& oRusties)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (oMatrix[i][j] == '!')
            {
                oRusties.push_back(make_pair(i, j));
            }
        }
    }
}

void getRusty(char** oMatrix)
{
    vector<pair<int, int>> oRusties;
    findRusties(oMatrix, oRusties);

    
    for (auto oRusty : oRusties)
    {
        if (oRusty.first > 0 && oMatrix[oRusty.first - 1][oRusty.second] != '#')
            oMatrix[oRusty.first - 1][oRusty.second] = '!';

        if (oRusty.first < 9 && oMatrix[oRusty.first + 1][oRusty.second] != '#')
            oMatrix[oRusty.first + 1][oRusty.second] = '!';

        if (oRusty.second > 0 && oMatrix[oRusty.first][oRusty.second - 1] != '#')
            oMatrix[oRusty.first][oRusty.second - 1] = '!';

        if (oRusty.second < 9 && oMatrix[oRusty.first][oRusty.second + 1] != '#')
            oMatrix[oRusty.first][oRusty.second + 1] = '!';
    }
    
}

void printMatrix(char** oMatrix)
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
            cout << oMatrix[i][j];

        cout << endl;
    }
}

void deleteMatrix(char** oMatrix)
{
    for (size_t i = 0; i < 10; i++)
        delete[] oMatrix[i];

    delete[] oMatrix;
}

int main()
{
    char** oMatrix = new char* [10];

    readMatrix(oMatrix);

    int nRustyTimes = 0;
    cin >> nRustyTimes;

    for (int i = 0; i < nRustyTimes; i++)
    {
        getRusty(oMatrix);
    }

    printMatrix(oMatrix);
    
    deleteMatrix(oMatrix);

    return 0;
}
