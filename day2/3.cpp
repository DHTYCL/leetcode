#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int lastIdx = -1;
    int maxCount = 0;
    vector<int>index(256, -1);
    for (int i = 0; i < s.size(); i++) {
        if (index[s[i]] == -1) {
            int tmpCount = i - lastIdx;
            if (tmpCount >= maxCount) {
                maxCount = tmpCount;
            }
        } else {
            if (lastIdx >= index[s[i]]) {
                int tmpCount = i - lastIdx;
                if (tmpCount >= maxCount) {
                    maxCount = tmpCount;
                }
            } else {
                lastIdx = index[s[i]]; 
                int tmpCount = i - lastIdx;
                if (tmpCount >= maxCount) {
                    maxCount = tmpCount;
                }
            } 
        }
        index[s[i]] = i;
    }
    return maxCount;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb");
    cout << lengthOfLongestSubstring("bbbbb");
    cout << lengthOfLongestSubstring("pwwkew");
    cout << lengthOfLongestSubstring("abcdef");
    cout << lengthOfLongestSubstring("fbcdef");
    cout << lengthOfLongestSubstring("tmmzuxt");
    return 0;
}
