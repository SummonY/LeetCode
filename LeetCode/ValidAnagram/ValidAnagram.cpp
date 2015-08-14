#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t)
        {
            vector<int> sVec(26, 0);
            vector<int> tVec(26, 0);
            int i;

            for (i = 0; i < s.size(); ++i) {
                sVec[s[i] - 'a']++;
            }

            for (i = 0; i < t.size(); ++i) {
                tVec[t[i] - 'a']++;
            }

            return sVec == tVec;
        }
};

int main()
{
    Solution sl;
    string s("hello");
    string t("world");

    cout << s << " with " << t << " isAnagram: ";
    if (sl.isAnagram(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
