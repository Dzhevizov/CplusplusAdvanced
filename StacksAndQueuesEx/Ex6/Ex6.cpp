#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int nPumpCount = 0;
    cin >> nPumpCount;

    queue<int> oFuel;
    queue<int> oDistances;

    for (size_t i = 0; i < nPumpCount; i++)
    {
        int nFuelQuantity = 0;
        cin >> nFuelQuantity;

        int nDistance = 0;
        cin >> nDistance;

        oFuel.push(nFuelQuantity);
        oDistances.push(nDistance);
    }

    for (size_t i = 0; i < nPumpCount; i++)
    {
        int nFuel = 0;
        bool bIsEnoughFuel = true;

        queue<int> oFuel1 = oFuel;
        queue<int> oDistances1 = oDistances;

        for (size_t j = 0; j < nPumpCount; j++)
        {
            int nCurrFuel = oFuel1.front();
            int nCurrDistance = oDistances1.front();

            nFuel += nCurrFuel;

            if (nFuel >= nCurrDistance)
            {
                oFuel1.pop();
                oFuel1.push(nCurrFuel);

                oDistances1.pop();
                oDistances1.push(nCurrDistance);

                nFuel -= nCurrDistance;
            }

            else
            {
                bIsEnoughFuel = false;
                break;
            }
        }
        
        if (bIsEnoughFuel)
        {
            cout << i << endl;
            break;
        }

        int nCurrStarterPumpFuel = oFuel.front();
        oFuel.pop();
        oFuel.push(nCurrStarterPumpFuel);

        int nCurrStarterPumpDistance = oDistances.front();
        oDistances.pop();
        oDistances.push(nCurrStarterPumpDistance);

    }
    return 0;
}
