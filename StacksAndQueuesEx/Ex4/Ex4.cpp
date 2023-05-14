#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int nFoodQuantity = 0;
    cin >> nFoodQuantity;

    cin.ignore();
    string strOrders;
    getline(cin, strOrders);

    stringstream oOrdersStream(strOrders);
    int nCurrOrder = 0;

    int nBiggestOrder = 0;

    queue<int> oOrders;

    while (oOrdersStream >> nCurrOrder)
    {
        if (nCurrOrder > nBiggestOrder)
        {
            nBiggestOrder = nCurrOrder;
        }

        oOrders.push(nCurrOrder);
    }

    cout << nBiggestOrder << endl;

    while (true)
    {
        if (oOrders.empty())
        {
            cout << "Orders complete" << endl;
            break;
        }

        nCurrOrder = oOrders.front();

        if (nFoodQuantity - nCurrOrder >= 0)
        {
            nFoodQuantity -= nCurrOrder;
            oOrders.pop();
        }

        else
        {
            cout << "Orders left:" << " ";

            while (!oOrders.empty())
            {
                cout << oOrders.front() << " ";
                oOrders.pop();
            }

            cout << endl;
            break;
        }
    }

    return 0;
}
