#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    int index = 0;
    if (strs.size() == 0) {
        return "";
    }
    if (strs.size() == 1) {
        return strs[0];
    }
    while (true) {
        for (int i = 0;i < strs.size(); i++) {
            if (strs[i].size() < index) {
                return strs[0].substr(0, index);
            } else {
                if (strs[i][index] != strs[0][index]) {
                    return strs[0].substr(0, index);
                }
            }
        }
        index++;
    }
    return strs[0].substr(0, index + 1);
}

int main()
{
    {
        vector<string> input;
        string str = "flower";
        input.push_back(str);
        str = "flow";
        input.push_back(str);
        str = "flight";
        input.push_back(str);
        cout << longestCommonPrefix(input) <<endl;
    }

    {
        vector<string> input;
        string str = "dog";
        input.push_back(str);
        str = "racecarr";
        input.push_back(str);
        str = "car";
        input.push_back(str);
        cout << longestCommonPrefix(input) <<endl;
    }
    return 0;
}
