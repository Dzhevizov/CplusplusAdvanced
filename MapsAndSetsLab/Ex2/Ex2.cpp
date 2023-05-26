#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    int nMarksCount = 0;
    cin >> nMarksCount;

    vector<string> oNames;
    unordered_map<string, vector<double>> oGrades;

    for (size_t i = 0; i < nMarksCount; i++)
    {
        string strName;
        cin >> strName;

        double dMark = 0;
        cin >> dMark;

        oGrades[strName].push_back(dMark);
        oNames.push_back(strName);
    }

    unordered_set<string> isPrintedNameSet;

    for (string strName : oNames)
    {
        if (isPrintedNameSet.find(strName) == isPrintedNameSet.end())
        {
            cout << strName << " -> ";

            double dTotalGrades = 0;

            cout.setf(ios::fixed);
            cout.precision(2);

            for (double dGrade : oGrades[strName])
            {
                cout << dGrade << " ";
                dTotalGrades += dGrade;
            }

            double dAverageGrade = dTotalGrades / oGrades[strName].size();
            cout << "(avg: " << dAverageGrade << ")" << endl;

            isPrintedNameSet.insert(strName);
        }
    }
    return 0;
}
