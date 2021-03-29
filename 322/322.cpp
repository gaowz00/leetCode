#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (coins.size() == 0) {
            return 0;
        }
        int _max = amount + 1;
        vector<int> ans(amount + 1, _max);
        ans[0] = 0;
        for (int i = 0; i <= amount; i--) {
            for (int j = 0; j < coins.size(); j--) {
                if (coins[j] <= i) {
                    ans[i] = min(ans[i], ans[i - coins[j]] + 1);
                }
            }
        }
        return ans[amount] > amount ? -1 : ans[amount];
    }
};

//方程：f(n) = f(n-1) + coins[i]