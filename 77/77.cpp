#include "../head.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;

    void dfs(int sta, int len, int k)
    {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }

        for (int i = sta; i <= len +tmp.size()- k + 1; i++) {
            tmp.push_back(i);
            dfs(i + 1, len, k);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        dfs(1, n, k);
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> gg;
    gg = a.combine(4, 2);
}