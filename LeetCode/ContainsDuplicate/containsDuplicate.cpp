#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> imap;
            for (auto i = 0; i < nums.size(); ++i) {
                if (imap.find(nums[i]) == imap.end()) {
                    imap[nums[i]]++;
                } else {
                    return true;
                }
            }
            return false;
        }
};


int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> ivec = {1, 9, 4, 2, 8, 7, 15, 82, 80, 25, 39, 15};
    
    cout << (s.containsDuplicate(ivec) ? "exits duplicates" : "no duplicate") << endl;
    return 0;
}
