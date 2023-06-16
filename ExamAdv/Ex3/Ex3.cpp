#include <iostream>
#include <map>

using namespace std;

int main()
{
    int nCitiesCount = 0;
    cin >> nCitiesCount;

    map<string, double> oShoppingBasket;

    while (oShoppingBasket.size() < nCitiesCount)
    {
        string strCityName;
        double nProductPrice;
        int nProductCount;

        cin >> strCityName >> nProductPrice >> nProductCount;

        double nSubTotal = nProductPrice * nProductCount;
        if (oShoppingBasket.find(strCityName) != oShoppingBasket.end())
        {
            oShoppingBasket[strCityName] += nSubTotal;
        }
        else
        {
            oShoppingBasket[strCityName] = nSubTotal;
        }
        
    }

    for (auto El : oShoppingBasket)
    {
        cout << El.first << " " << El.second << endl;
    }

    return 0;
}
