#include "../head.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '#' && i > 0){
                s.erase(i -1, 2);
                i = i - 2;
                n = n - 2;
            }
            else if(s[i] == '#'){
                s.erase(i, 1);
                i--;
                n--;
            }
        }
        for(int i = 0; i < n; i++){
            if(t[i] == '#' && i > 0){
                t.erase(i - 1, 2);
                i = i - 2;
                n = n - 2;
            }
            else if(t[i] == '#'){
                t.erase(i, 1);
                i--;
                n--;
            }
        }
        if(s == t){
            return true;
        }
        return false;
    }
};

int main(){
    Solution a;
    string s1 = "ab#c";
    string b = "ad#c";
    bool ans = a.backspaceCompare(s1, b);
    cout<<ans;
}