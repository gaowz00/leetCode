#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        auto f = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, false));

        int l1 = s1.length(), l2 = s2.length();
        int l3 = s3.length();
        if (l3 != l1 + l2) {
            return false;
        }
        f[0][0] = true;
        for (int i = 0; i < l1 + 1; i++) {
            for (int j = 0; j < l2 + 1; j++) {
                if (i > 0) {
                    f[i][j] |= f[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0) {
                    f[i][j] |= f[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return f[l1][l2];
    }
};