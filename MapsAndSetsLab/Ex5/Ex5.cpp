#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    vector<string> oParkedCars;

    while (strInput != "END")
    {
        istringstream iStr(strInput);
        vector<string> oInput;

        while (getline(iStr >> ws, strInput, ','))
        {
            oInput.push_back(strInput);
        }

        string strComand = oInput[0];
        string strRegNumber = oInput[1];
        
        if (strComand == "IN")
        {
            auto it = find(oParkedCars.begin(), oParkedCars.end(), strRegNumber);
            if (it == oParkedCars.end())
                oParkedCars.push_back(strRegNumber);
            
        }
        else if (strComand == "OUT")
        {
            auto it = find(oParkedCars.begin(), oParkedCars.end(), strRegNumber);
            if (it != oParkedCars.end())
                oParkedCars.erase(it);
        }

        getline(cin, strInput);
    }

    if (oParkedCars.empty())
    {
        cout << "Parking Lot is Empty" << endl;
    }
    else
    {
        for (string strCar : oParkedCars)
        {
            cout << strCar << endl;
        }
    }

    return 0;
}
