#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nShoppingItemsCount = 0;
    cin >> nShoppingItemsCount;

    map<string, double> oShoppingBasket;
    double dTotalSum = 0;
    vector <double> oPrices;
    vector <string> oProducts;

    for (int i = 0; i < nShoppingItemsCount; i++)
    {
        string strProductName;
        double dProductPrice;
        int nProductCount;

        cin >> strProductName >> dProductPrice >> nProductCount;

        double dSubTotal = dProductPrice * nProductCount;
        dTotalSum += dSubTotal;
        oShoppingBasket[strProductName] = dSubTotal;
        oPrices.push_back(dSubTotal);
        oProducts.push_back(strProductName);
    }

    cout << "The total sum is: " << dTotalSum << " lv." << endl;

    sort(oPrices.begin(), oPrices.end(), greater<double>());

    bool isPrinted = false;

    vector<bool> oFlags;
    for (int i = 0; i < oProducts.size(); i++)
    {
        oFlags.push_back(false);
    }

    for (int j = 0; j < oPrices.size(); j++)
    {
        for (int i = 0; i < oProducts.size(); i++)
        {
            if (oShoppingBasket[oProducts[i]] == oPrices[j] && oFlags[i] == false)
            {
                cout << oProducts[i] << " " << oPrices[j] << endl;
                oFlags[i] = true;
            }
        }
    }
    
    return 0;
}
