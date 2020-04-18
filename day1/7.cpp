#include <iostream>
#include <climits>
using namespace std;

//123
int reverse(int x)
{
    long long int res = 0;
    int index = 1;
    long long int num = x;
    if (num < 0) {
        num = -num;
        index = -1;
    }
    while(num != 0) {
        res =res*10 + (num%10) ;
        num=num/10;
    }
    if (res > INT_MAX || res < INT_MIN) {
        return 0;
    }
    return res*index;
}

int main()
{
    int x = 123;
    int res = reverse(x);
    cout << res <<endl;

    x = -123;
    res = reverse(x);
    cout << res <<endl;

    x = 1534236469; 
    res = reverse(x);
    cout << res <<endl;

    x = -2147483648; 
    res = reverse(x);
    cout << res <<endl;
    return 0;
}
