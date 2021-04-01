#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        bool dp[n][n]; 
        string ans;
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = true;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (dp[i + 1][j - 1] && (s[j] == s[i]));
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i,l+1);
                }
            }

        }
        return ans;
    }
};