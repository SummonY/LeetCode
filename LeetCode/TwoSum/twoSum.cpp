#include <iostream>
#include "twoSum.hpp"

using std::cout;
using std::endl;

int main()
{
    Solution s;
    vector<int> array={13, 20, 9, 6, 3, 2, 7, 11, 15};
    vector<int> ivec;

    ivec = s.twoSum(array, 9);
    cout << "index1=" << ivec[0] << ", index2=" << ivec[1] << endl;
    return 0;
}
