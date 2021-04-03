#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<char, string> phoneMap {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string tmp;
        dfs(0, ans, tmp, digits);
        return ans;
    }
    void dfs(int _dep, vector<string>& ans, string& tmp, const string _digits)
    {
        if (_dep == _digits.size()) {
            ans.push_back(tmp);
            return;
        }
        const string& _letter = phoneMap.at(_digits[_dep]);
        for (const char& l : _letter) {
            tmp.push_back(l);
            dfs(_dep + 1, ans, tmp, _digits);
            tmp.pop_back();
        }
        return;
    }
};