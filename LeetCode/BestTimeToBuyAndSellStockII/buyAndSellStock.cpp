#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max = 0, profit;
            for (auto i = 1; i < prices.size(); ++i) {
                profit = prices[i] - prices[i - 1];
                if (profit < 0) {
                    continue;
                }
                max += profit;
            }
            return max;
        }
};

int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> ivec = {6, 3, 7, 3, 2, 10, 1, 9, 7, 6, 5, 20, 10, 3};

    cout << "maximum profit = " << s.maxProfit(ivec) << endl;
    return 0;
}
