#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, 0, target, candidates, tmp);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, int first, int num, vector<int>& _nums, vector<int>& tmp)
    {
        if (num < 0) {
            return;
        }
        if (num == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = first; i < _nums.size(); i++) {
            tmp.push_back(_nums[i]);
            dfs(ans, i, num - _nums[i], _nums, tmp);
            tmp.pop_back();
        }
    }
};
