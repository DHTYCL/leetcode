#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int num = nums1.size() + nums2.size();
    int idx = 0;
    vector<int> res(num);
    for(int idx1 = 0, idx2 = 0; idx1<nums1.size()||idx2<nums2.size();) {
        if (idx1 == nums1.size()) {
            res[idx++] =nums2[idx2++];
            continue;
        }
        if (idx2 == nums2.size()) {
            res[idx++] =nums1[idx1++];
            continue;
        }
        if (nums1[idx1] < nums2[idx2]) {
            res[idx++] =nums1[idx1++];
        } else {
            res[idx++] =nums2[idx2++];
        }
    }
    if (num%2 == 0) {
       return (res[num/2-1] + res[num/2])/2.0;
    } else {
       return res[num/2];
    }
}

int main(){
    return 0;
}
