#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    string str = "";
    int T = numRows * 2 -2;
    if (numRows == 1) {
        return s;
    }
    vector<string> res(numRows, "");
    for (int i = 0;i < s.size(); i++) {
        int n = i%T;
        if (n < numRows) { 
            res[n] += s[i];
        } else {
            res[T-n] += s[i];
        }
    }
    for (int i = 0;i < numRows; i++) {
        str += res[i];
    }
    return str;
}

int main(){
    string s = "LEETCODEISHIRING";
    string str = convert(s, 3);
    cout << str << endl;

    s = "LEETCODEISHIRING";
    str = convert(s, 4);
    cout << str << endl;

    s = "A";
    str = convert(s, 1);
    cout << str << endl;
    return 0;
}
