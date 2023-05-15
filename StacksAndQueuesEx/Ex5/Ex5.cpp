#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    stringstream oStream(strInput);
    stack<int> oClothes;
    int nCurrClothing = 0;

    while (oStream >> nCurrClothing)
    {
        oClothes.push(nCurrClothing);
    }

    int nRackCapacity = 0;
    cin >> nRackCapacity;

    int nClothingSum = 0;
    int nRacksCount = 1;

    while (!oClothes.empty())
    {
        int nCurrClothing = oClothes.top();

        if (nClothingSum + nCurrClothing > nRackCapacity)
        {
            nRacksCount++;
            nClothingSum = nCurrClothing;
        }

        else if (nClothingSum + nCurrClothing == nRackCapacity && oClothes.size() > 1)
        {
            nRacksCount++;
            nClothingSum = 0;
        }

        else
        {
            nClothingSum += nCurrClothing;
        }

        oClothes.pop();
    }

    cout << nRacksCount << endl;

    return 0;
}
