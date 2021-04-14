#include "../head.h"

using namespace std;

int main()
{

    vector<int> arr { 8, 4, 5, 0, 0, 0, 0, 7 };
    int n = arr.size();
    int num = 0;
    int t = 0;
    for (int i = 0; i < n - num; i++) {
        if (arr[i] == 0) {
            num++;
        }
        t++;
    }
    int j = (n == (t + num)) ? -1 : t - 1;
    t--;
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = arr[t];
        if (arr[i] == 0 && t != j) {
            if (--i > 0) {
                arr[i] = 0;
            }
        }
        t--;
    }
}