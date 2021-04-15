#include "../head.h"

using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        int fir = nums[start];
        int sec = max(nums[start], nums[start + 1]); 
        for(int i = start + 2; i <= end; i++){
            int tmp = sec;
            sec = max(sec, nums[i] + fir);
            fir = tmp;
        }
        return sec;
    }
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int len = nums.size();
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
    }
};