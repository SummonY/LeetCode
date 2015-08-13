#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int count = 0;
            
            for (int i = s.size() - 1; i >= 0; --i) {
                if (count > 0 && s[i] == ' ') {
                    return count;
                }
                if (s[i] == ' ')
                    continue;
                ++count;
            }
            return count;
        }
};


int main()
{
    Solution s;
    string str("a ");
    cout << "Length of last word = " << s.lengthOfLastWord(str) << endl;
    return 0;
}
