/*
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 */

#include <iostream>
#include <vector>

using namespace std;

class MajorityElement {
    public:
        int majorityElement(vector<int> &nums) {
            int max, count = 0;
            int size = nums.size();

            for (int i = 0; i < size; ++i) {
                if (count == 0) {
                    max = nums[i];
                    ++count;
                    continue;
                }
                if (max != nums[i])
                    count--;
                else
                    count++;
            }
            return max;
        }
};

int main()
{
    MajorityElement me;
    
    vector<int> nums = {5, 3, 0, 3, 2, 8, 3, 2, 3, 3, 0, 3, 3, 0};
    cout << "The most majority element: " << me.majorityElement(nums) << endl;
    return 0;
}
