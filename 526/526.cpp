#include "../head.h"

using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(int _n, int start, vector<bool>& _visit)
    {
        if (start > _n) {
            ans++;
            return;
        }
        for (int i = 1; i <= _n; i++) {
            if (!_visit[i] && (start % i == 0 || i % start == 0))
            {
                _visit[i] = true;
                dfs(_n, start + 1, _visit);
                _visit[i] = false;
            }
      }

    }
    int countArrangement(int n)
    {
        vector<bool> isVisit(n+1, false);
        dfs(n, 1, isVisit);
        return ans;
    }
};