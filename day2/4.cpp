#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int expand(string s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0;i < s.size(); i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start +1) {
            end = i + len/2;
            start = end - len +1;
        }
    }
    return s.substr(start, end - start + 1);
}


int main(){
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("abba") << endl;
    return 0;
}
