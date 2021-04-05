#include "../head.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans{};
    vector<int> tmp;

    void dfs(int start, int len, vector<int> &_nums)
    {
        ans.push_back(tmp);
        for (int i = start; i < len; i++)
        {
            tmp.push_back(_nums[i]);
            dfs(i + 1, len, _nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int len = nums.size();
        dfs(0, len, nums);
        return ans;
    }
};