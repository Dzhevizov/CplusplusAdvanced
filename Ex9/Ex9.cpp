#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int nGreenLightDuration = 0;
    cin >> nGreenLightDuration;

    int nFreeWindowDuration = 0;
    cin >> nFreeWindowDuration;

    string strInput;
    cin >> strInput;

    queue<string> oTrafficQueue;
    int nPassedCars = 0;

    while (strInput != "END")
    {
        if (strInput != "green")
        {
            oTrafficQueue.push(strInput);
            cin >> strInput;
            continue;
        }

        int nPassedParts = 0;

        while (nPassedParts < nGreenLightDuration)
        {
            if (oTrafficQueue.empty())
            {
                break;
            }

            string strCurrCarr = oTrafficQueue.front();

            for (char chLetter : strCurrCarr)
            {
                nPassedParts++;
                if (nPassedParts > nGreenLightDuration + nFreeWindowDuration)
                {
                    cout << "A crash happened!" << endl;
                    cout << strCurrCarr << " was hit at " << chLetter << endl;
                    return 0;
                }
            }

            oTrafficQueue.pop();
            nPassedCars++;
        }
        
        cin >> strInput;
    }

    cout << "Everyone is safe." << endl;
    cout << nPassedCars << " total cars passed the crossroads." << endl;
    return 0;
}
