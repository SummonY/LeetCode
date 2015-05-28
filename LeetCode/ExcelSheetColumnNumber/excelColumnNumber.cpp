#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int titleToNumber(string s) {
            uint32_t col = 0;
            int val;
            for (int i = 0; i < s.size(); ++i) {
                col = col * 26 + (s.at(i) - 'A' + 1);
            }
            return col;
        }
};

int main(int argc, const char *argv[])
{
    Solution s;
    string str("BZ");

    cout << "column number = " << s.titleToNumber(str) << endl;
    return 0;
}
