#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ans = { {} };
        std::sort(nums.begin(), nums.end());
        //int n = nums.size();
        dfs(nums, ans, 0);
        return ans;
    }
    void dfs(vector<int>& _nums, vector<vector<int>>& ans, int _begin)
    {
        if (_begin == _nums.size()) {
            return;
        }
        std::sort(_nums.begin()+_begin, _nums.end());
        // bool _is;
        // vector<int> t(_nums.begin() + _begin, _nums.end());
        // for (int e = 0; e < ans.size(); e++) {
        //     if (ans[e] == t)
        //         _is = true;
        // }
        // if (!_is)
            ans.emplace_back(_nums.begin() + _begin, _nums.end());
        for (int i = _begin; i < _nums.size(); i++) {
            if (_nums[i] == _nums[i - 1] && i != _begin) {
                continue;
            }

            swap(_nums[_begin], _nums[i]);
            _begin++;
            dfs(_nums, ans, _begin);
            _begin--;
            swap(_nums[_begin], _nums[i]);
        }
    }
};

int main()
{
    Solution X;
    vector<int> aa = { 1, 2, 3, 4 };
    vector<vector<int>> nn;
    nn = X.subsetsWithDup(aa);
    for (int i = 0; i < nn.size(); i++) {
        for (int j = 0; j < nn[i].size(); j++) {
            std::cout << nn[i][j];
        }
        std::cout << endl;
    }
    return 0;
}