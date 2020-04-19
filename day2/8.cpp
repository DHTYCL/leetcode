#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int calc(string str, int i, int flag)
{
    long long res = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        res = res*10 + (str[i++]- '0');
        if (res *flag >INT_MAX) {
            return INT_MAX;
        }
        if (res*flag < INT_MIN) {
            return INT_MIN;
        }
    }
    res = res * flag;
    return int(res);
}

int myAtoi(string str)
{
    int i = 0;
    int flag = 1;
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '+') {
        flag = 1;
        return calc(str, i + 1, flag);
    } else if (str[i] == '-') {
        flag = -1;
        return calc(str, i + 1, flag);
    } else if (str[i] >= '0' && str[i] <= '9')  {
        flag = 1;
        return calc(str, i, flag);
    } else {
        return 0;
    }
}

int main(){
    string str = "42";
    cout << myAtoi(str) <<endl;

    str = "   -42";
    cout << myAtoi(str) <<endl;

    str = "4193 with words";
    cout << myAtoi(str) <<endl;

    str = "words and 987";
    cout << myAtoi(str) <<endl;

    str = "-91283472332";
    cout << myAtoi(str) <<endl;

    str = "1";
    cout << myAtoi(str) <<endl;

    str = "";
    cout << myAtoi(str) <<endl;

    str = "+";
    cout << myAtoi(str) <<endl;

    str =" ";
    cout << myAtoi(str) <<endl;

    str ="+-2";
    cout << myAtoi(str) <<endl;
    return 0;
}
