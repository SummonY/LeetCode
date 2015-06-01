#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int singleNumber1(vector<int>& nums) {
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

        int singleNumber2(vector<int>& nums) {
            int ones = 0, twos = 0;
            for (int i = 0; i < nums.size(); ++i) {
                ones = (ones ^ nums[i]) & ~twos;
                twos = (twos ^ nums[i]) & ~ones;
            }
            return ones;
        }
};


int main(int argc, const char *argv[])
{
    vector<int> ivec = {3, 5, 8, 9, 3, 9, 8, 3, 9, 8};
    Solution sn;

    cout << "single number = " << sn.singleNumber1(ivec) << endl;
    cout << "single number = " << sn.singleNumber2(ivec) << endl;
    return 0;
}
