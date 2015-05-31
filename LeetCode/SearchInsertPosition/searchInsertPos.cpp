#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int i, size;
            size = nums.size();

            for (i = 0; i < size; ++i) {
                if (target <= nums[i]) {
                    return i;
                }
                if (target > nums[i]) {
                    continue;
                }
                if (target < nums[i]) {
                    return i;
                }
            }
            if (i == size)
                return size;
        }
};

int main(int argc, const char *argv[])
{
    Solution sn;
    vector<int> ivec = {0, 2, 3, 5, 6, 7, 8, 9, 10, 13, 16, 20, 30, 52};
    int target = 20;

    cout << "postion = " << sn.searchInsert(ivec, target) << endl;
    return 0;
}
