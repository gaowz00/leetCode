#include "../head.h"

using namespace std;

class Solution {
public:
    int _max = 0;

    void dfs(int n, int m, vector<vector<int>>& grid, int i, int j, int& ans, int sum)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == 0) {
            return;
        }
        int tmp = grid[i][j];
        sum += grid[i][j];
        ans = max(sum, ans);
        grid[i][j] = 0;

        dfs(n, m, grid, i + 1, j, ans, sum);
        dfs(n, m, grid, i - 1, j, ans, sum);
        dfs(n, m, grid, i, j + 1, ans, sum);
        dfs(n, m, grid, i, j - 1, ans, sum);

        grid[i][j] = tmp;
        return;
    }
    int get_MaximumGold(vector<vector<int>>& grid)
    {
        int depth = grid.size();
        int width = grid[0].size();
        for (int i = 0; i < depth; i++) {
            for (int j = 0; j < width; j++) {
                int ans = 0;
                if (grid[i][j]) {
                    dfs(depth, width, grid, i, j, ans ,0);
                    _max = max(_max, ans);
                }
            }
        }
        return _max;
    }
};