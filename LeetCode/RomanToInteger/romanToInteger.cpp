#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int sum = 0;
            map<char, int> imap = {{'I', 1}, {'V', 5}, {'X', 10}, 
                {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            for (auto i = 0; i < s.size();) {
                if (imap[s[i + 1]] > imap[s[i]]) {
                    sum += imap[s[i + 1]] - imap[s[i]];
                    i += 2;
                } else {
                    sum += imap[s[i]];
                    ++i;
                }
            }
            return sum;
        }
};

int main(int argc, const char *argv[])
{
    Solution sn;
    string s("MMMCMXCIX");

    cout << "int num = " << sn.romanToInt(s) << endl;
    return 0;
}
