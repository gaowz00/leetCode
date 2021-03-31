#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int high = m * n - 1, low = 0;
        int mid = (high + low) / 2;
        while (high >= low) {
            if (matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] > target) {
                high = mid - 1;
                mid = (high + low) / 2;
            } else {
                low = mid + 1;
                mid = (high + low) / 2;
            }
        }
        return false;
    }
};