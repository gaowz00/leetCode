#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;




class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        int n = answers.size();
        int ans = 0;
        if (!n) {
            return 0;
        }
        if (n == 1) {
            return answers[1] + 1;
        }
        vector<int> _hash(1001, 0);
        for (int i = 0; i < n; i++) {
            _hash[answers[i]]++;
        }
        for (int i = 0; i < 1001; i++) {
            if (_hash[i] > 0) {
                if (_hash[i] <= i + 1) {
                    ans += i + 1;
                } else {
                    int tmp = _hash[i] / (i + 1);
                    ans += tmp * (i + 1);
                    int t = _hash[i] % (i + 1);
                    if (t) {
                        ans += i + 1;
                    }
                }
            }
        }
        return ans;
    }
};



int main(){
    vector<int> aa{2,1,2,2,2,2,2,2,1,1};
    Solution a;
    int out = a.numRabbits(aa);
    std::cout<<out;
    
}