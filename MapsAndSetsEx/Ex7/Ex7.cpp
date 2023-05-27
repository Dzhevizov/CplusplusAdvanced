#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    string strResource;
    cin >> strResource;

    vector<string> oResources;
    unordered_map<string, int> oResourcesquantity;

    while (strResource != "stop")
    {
        int nQuantity = 0;
        cin >> nQuantity;

        if (oResourcesquantity.find(strResource) == oResourcesquantity.end())
            oResources.push_back(strResource);

        oResourcesquantity[strResource] += nQuantity;

        cin >> strResource;
    }

    for (string strRes : oResources)
    {
        cout << strRes << " -> " << oResourcesquantity[strRes] << endl;
    }
    return 0;
}
