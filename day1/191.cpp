#include <iostream>
using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0;i < 32;i++) {
       if ((n >>i) & 0x01 == 1) {
            count ++;
       }
    }
    return count;
}

int main()
{
    uint32_t n = 0xffffffff;
    int res = hammingWeight( n);
    cout << res <<endl;


    n = 0xff;
    res = hammingWeight( n);
    cout << res <<endl;
    return 0;
}
