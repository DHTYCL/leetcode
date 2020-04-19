#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;
/*一般的数组问题都需要用双指针的方法解决，这道题也是。
 * 所以，我们可以定义左右两个指针l和r分别代表数组第一个和最后一个的元素。
 * 由于是查找最大的面积，即计算high*width。high为nums[l]或nums[r]之间比较小的一个，
 * width为r-l；若nums[l]比nums[r]小，则l++；若nums[l]比nums[r]大，则r–；当l==r则结束。
 * 因为l或r往里移动都可能会使面积减小，所以将两端较小的一端往里移动才可能会使面积增大。
 * 用一个变量保存当前最大面积，结束就输出。
 *
*/
int maxArea(vector<int>& height) 
{
    int area = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
        area = max(area, min(height[l], height[r])*(r - l));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return area;
}

int main()
{
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}
