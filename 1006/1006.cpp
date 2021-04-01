#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int clumsy(int N)
    {
        int n = N / 4, m = N % 4;
        int ans = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            temp = fabs(N * (N - 1) / (N - 2)) + (N - 3);
            if (i == 0) {
                ans = temp;
            } else {
                ans = ans - temp + 2 * (N - 3);
            }
            N = N - 4;
        }
        if (m == 1) {
            temp = N;
        } else if (m == 2) {
            temp = N * (N - 1);
        } else if (m == 3) {
            temp = fabs(N * (N - 1) / (N - 2));
        } else {
            temp = 0;
        }
        if (n == 0) {
            return temp;
        } else {
            return ans - temp;
        }
    }
};