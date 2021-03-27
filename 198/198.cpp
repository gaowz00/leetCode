#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        unsigned char n = nums.size();
        vector<int> f(n);
        if (nums.empty())
            return 0;
        if (n == 1)
            return nums[0];
        f[0] = nums[0];
        //f[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            if (f[i - 2] + nums[i] > f[i - 1]) {
                f[i] = f[i - 2] + nums[i];
            } else {
                f[i] = f[i - 1];
            }
        }
        return f.back();
    }
};
