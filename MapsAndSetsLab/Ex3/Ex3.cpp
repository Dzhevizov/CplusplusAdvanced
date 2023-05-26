#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    int nCitiesCount;
    cin >> nCitiesCount;

    unordered_map<string, unordered_map<string, vector<string>>> oCitiesMap;
    vector<string> oCountries;
    vector<string> oContinents;

    for (size_t i = 0; i < nCitiesCount; i++)
    {
        string strContinent, strCountry, strCity;
        cin >> strContinent >> strCountry >> strCity;

        oCitiesMap[strContinent][strCountry].push_back(strCity);
        oContinents.push_back(strContinent);
        oCountries.push_back(strCountry);
    }

    unordered_set<string> oPrintedContinents;
    unordered_set<string> oPrintedCountries;

    for (string strCurrContinent : oContinents)
    {
        if (oPrintedContinents.find(strCurrContinent) != oPrintedContinents.end())
            continue;

        cout << strCurrContinent << ":" << endl;

        for (string strCurrCountry : oCountries)
        {
            if (oPrintedCountries.find(strCurrCountry) != oPrintedCountries.end() ||
                oCitiesMap[strCurrContinent].find(strCurrCountry) == oCitiesMap[strCurrContinent].end())
                continue;

            cout << "\t" << strCurrCountry << " -> ";

            for (size_t i = 0; i < oCitiesMap[strCurrContinent][strCurrCountry].size(); i++)
            {
                cout << oCitiesMap[strCurrContinent][strCurrCountry][i];

                if (i < oCitiesMap[strCurrContinent][strCurrCountry].size() - 1)
                    cout << ", ";
                else
                    cout << endl;
            }

            oPrintedCountries.insert(strCurrCountry);
        }
       
        oPrintedContinents.insert(strCurrContinent);
    }

    return 0;
}
