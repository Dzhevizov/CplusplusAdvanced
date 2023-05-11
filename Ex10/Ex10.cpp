#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int nBulletPrice = 0;
    cin >> nBulletPrice;

    int nBarrelSize = 0;
    cin >> nBarrelSize;

    cin.ignore();

    string strBullets;
    getline(cin, strBullets);
    stringstream oBulletsStream(strBullets);
    int nBullet = 0;

    stack<int> oBullets;

    while (oBulletsStream >> nBullet)
    {
        oBullets.push(nBullet);
    }

    string strLocks;
    getline(cin, strLocks);
    stringstream oLocksStream(strLocks);
    int nLock = 0;

    queue<int> oLocks;

    while (oLocksStream >> nLock)
    {
        oLocks.push(nLock);
    }

    int nIntelligenceValue = 0;
    cin >> nIntelligenceValue;

    int nShoots = 0;

    while (true)
    {
        if (oLocks.empty())
        {
            cout << oBullets.size() << " bullets left. Earned $" << nIntelligenceValue << endl;
            return 0;
        }

        if (oBullets.empty())
        {
            cout << "Couldn't get through. Locks left: " << oLocks.size() << endl;
            return 0;
        }

        int nCurrLock = oLocks.front();
        int nCurrBullet = oBullets.top();

        if (nCurrBullet <= nCurrLock)
        {
            cout << "Bang!" << endl;
            oLocks.pop();
        }
        else
        {
            cout << "Ping!" << endl;
        }

        oBullets.pop();
        nShoots++;
        nIntelligenceValue -= nBulletPrice;

        if (nShoots == nBarrelSize && !oBullets.empty())
        {
            cout << "Reloading!" << endl;
            nShoots = 0;
        }
    }

    return 0;
}
