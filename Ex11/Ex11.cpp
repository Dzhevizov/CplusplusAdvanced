#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    string strCups;
    getline(cin, strCups);
    stringstream oCupsStream(strCups);
    int nCup = 0;

    queue<int> oCups;

    while (oCupsStream >> nCup)
    {
        oCups.push(nCup);
    }

    string strBottles;
    getline(cin, strBottles);
    stringstream oBottlesStream(strBottles);
    int nBottle = 0;

    stack<int> oBottles;

    while (oBottlesStream >> nBottle)
    {
        oBottles.push(nBottle);
    }

    int nWastedWater = 0;

    while (true)
    {
        if (oCups.empty())
        {
            cout << "Bottles: ";
            while (!oBottles.empty())
            {
                cout << oBottles.top() << " ";
                oBottles.pop();
            }
            cout << endl;
            break;
        }

        if (oBottles.empty())
        {
            cout << "Cups: ";
            while (!oCups.empty())
            {
                cout << oCups.front() << " ";
                oCups.pop();
            }
            cout << endl;
            break;
        }

        int nCurrCup = oCups.front();
        int nCurrBottle = oBottles.top();

        if (nCurrBottle >= nCurrCup)
        {
            nWastedWater += nCurrBottle - nCurrCup;
            oCups.pop();
        }
        else
        {
            oCups.front() -= nCurrBottle;
        }

        oBottles.pop();
    }

    cout << "Wasted litters of water: " << nWastedWater << endl;
    
    return 0;
}
