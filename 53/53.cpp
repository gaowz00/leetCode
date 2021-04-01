#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int ans;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = nums[i];
                } else {
                    if (dp[i][j - 1] + nums[j] > 0) {
                        dp[i][j] = dp[i][j - 1] + nums[j];
                    } else {
                        dp[i][j] = nums[j];
                    }
                }
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};