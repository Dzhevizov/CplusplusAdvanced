#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int nPassedCarsPerGreenLight = 0;
    cin >> nPassedCarsPerGreenLight;

    queue<string> oTrafficQueue;

    cin.ignore();
    string strCurrCarr;
    getline(cin, strCurrCarr);

    int nPassedCarsCount = 0;

    while (strCurrCarr != "end")
    {
        if (strCurrCarr != "green")
        {
            oTrafficQueue.push(strCurrCarr);
            getline(cin, strCurrCarr);
            continue;
        }

        for (int i = 0; i < nPassedCarsPerGreenLight; i++)
        {
            if (oTrafficQueue.empty())
            {
                break;
            }
            cout << oTrafficQueue.front() << " passed!" << endl;
            oTrafficQueue.pop();
            nPassedCarsCount++;
        }
        
        getline(cin, strCurrCarr);
    }

    cout << nPassedCarsCount << " cars passed the crossroads." << endl;
    return 0;
}
