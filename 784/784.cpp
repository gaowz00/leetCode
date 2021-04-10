#include "../head.h"

using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(int len, int start, string _S)
    {
        if (start >= len) {
            ans.push_back(_S);
            return;
        }
        dfs(len, start + 1, _S);
        if (_S[start] >= 'A' && _S[start] <= 'z') {

            _S[start] = _S[start] ^ 32;
            dfs(len, start + 1, _S);
        }
    }
    vector<string> letterCasePermutation(string S)
    {
        int len = S.size();
        dfs(len, 0, S);
        return ans;
    }
};

int main()
{
    Solution a;
    string s = "a1b2";
    vector<string> bb = a.letterCasePermutation(s);
    for (int i = 0; i < bb.size(); i++) {
        cout << bb[i] << endl;
    }
}