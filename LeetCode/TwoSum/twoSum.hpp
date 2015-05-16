#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> m;
            vector<int> result;
            for (int i = 0; i != nums.size(); ++i) {
                if (m.find(nums[i]) == m.end()) {
                    m[target - nums[i]] = i;
                } else {
                    result.push_back(m[nums[i]] + 1);
                    result.push_back(i + 1);
                    break;
                }
            }
            return result;
        }

};
