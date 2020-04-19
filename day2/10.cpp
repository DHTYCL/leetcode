#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

bool isMatch(string s, string p) 
{
    //若p为空，则需s同时为空才匹配
    if (p.empty()) {
        return s.empty();
    }
    //判断s的第1个字符是否直接匹配
    bool firstMatch = false;
    if (!s.empty() && (p[0] == s[0] || p[0] == '.')) {
        firstMatch = true;
    }
    //提前1个字符检测'*'，并分类讨论（'*'不可能出现在第1个位置）
    if (p.size() >= 2 && p[1] == '*') {
        /*
            可能匹配的两种情况：
            (1)isMatch(s, p.substr(2))
               代表'*'可能将前1字符重复了0次，故从'*'后位置继续匹配
            (2)(first_match && isMatch(s.substr(1), p))
               代表s中第1个字符已匹配，留下p的第1个字符从s的下一个字符继续匹配
        */
        return  isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
    } else {
        //暂无'*'且第1个字符匹配，继续匹配
        return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
}

int main()
{
    cout << isMatch("aa", "a") << false << endl;
    cout << isMatch("aa", "a*") << true<< endl;
    cout << isMatch("ab", ".*") << true<< endl;
    cout << isMatch("aab", "c*a*b") << true<< endl;
    cout << isMatch("aab", "c*a*b") << true<< endl;
    cout << isMatch("mississippi", "mis*is*p*.") << false<< endl;
    return 0;
}
