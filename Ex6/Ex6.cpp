#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string strInput;
    cin >> strInput;

    queue <string> oNames;

    while (strInput != "End")
    {
        if (strInput == "Paid")
        {
            while (!oNames.empty())
            {
                cout << oNames.front() << endl;
                oNames.pop();
            }
        }

        else
        {
            oNames.push(strInput);
        }
        
        cin >> strInput;
    }

    size_t nQueueSize = oNames.size();

    cout << nQueueSize << " people remaining." << endl;

    return 0;
}
