#include <iostream>
#include <map>
#include "SingleNumber.hpp"

using std::cout;
using std::endl;
using std::map;

int SingleNumber::singleNumber(vector<int>& nums) {
    map<int, int> imap;
    int i;

    for (i = 0; i < nums.size(); ++i) {
        imap[nums[i]]++;
    }
    for (i = 0; i < nums.size(); ++i) {
        if (imap[nums[i]] == 1) {
            return nums[i];
        }
    }
}

int main(int argc, const char *argv[])
{
    vector<int> ivec{3, 9, 6, 3, 0, 2, 0, 2, 6, 9, 100, 3};
    SingleNumber sN;
    int singNum;

    singNum = sN.singleNumber(ivec);
    cout << singNum << endl;
    return 0;
}
