#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

bool isPalindrome(int x) 
{
    int input = x;
    if (input < 0) {
        return false;
    }
    long long result = 0;
    while (input != 0) {
        result =result* 10 + input%10;
        input/=10;
    }
    if (result > INT_MAX) {
        return false;
    }
    return int(result) == x;
    
}
int main()
{
    cout << isPalindrome(121)<< endl;
    cout << isPalindrome(-121)<< endl;
    cout << isPalindrome(10)<< endl;
    return 0;
}
