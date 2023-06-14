#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    string strInput;
    getline(cin, strInput);

    vector<string> oCities;
    unordered_map<string, pair<string, string>> oCitiesMap;

    while (strInput != ".")
    {
        vector<string> oInput;
        string strCurrWord;
        for (size_t i = 0; i < strInput.length(); i++)
        {
            if (strInput[i] == ',')
            {
                oInput.push_back(strCurrWord);
                strCurrWord = "";
                continue;
            }
                
            strCurrWord += strInput[i];
        }

        oInput.push_back(strCurrWord);

        oCities.push_back(oInput[0]);
        oCitiesMap[oInput[0]] = make_pair(oInput[1], oInput[2]);

        getline(cin, strInput);
    }

    string strQuery;
    getline(cin, strQuery);

    while (strQuery != ".")
    {
        bool isCity = false;

        for (string strCity : oCities)
        {
            if (strCity == strQuery)
            {
                cout << strCity << "," << oCitiesMap[strCity].first << "," << oCitiesMap[strCity].second << endl;
                isCity = true;
                break;
            }
        }

        if (!isCity)
        {
            istringstream iStr(strQuery);
            string strLatitude, strLongitude;
            iStr >> strLatitude >> strLongitude;

            for (string strCity : oCities)
            {
                if (oCitiesMap[strCity] == pair<string, string>(strLatitude, strLongitude))
                    cout << strCity << "," << oCitiesMap[strCity].first << "," << oCitiesMap[strCity].second << endl;
            }
        }

        getline(cin, strQuery);
    }
    return 0;
}
