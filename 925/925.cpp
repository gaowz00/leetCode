#include "../head.h"

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        if(n > m){
            return false;
        }
        int i = 0, j = 0;
        char pre;
        while(i < n  && j < m ){
            if(name[i] == typed[j]){
                pre = name[i];
                i++;
                j++;
            }
            else if(name[i] != typed[j] && typed[j] == pre){
                j++;
            }
            else {
                return false;
            }
        }
        while(j < m){
            if(typed[j] != pre){
                return false;
            }
            j++;
        }
        return (i == n)? true : false;

    }
};


int main(){
    Solution A;
    string a = "alex";
    string b = "aaleex";
    bool ans = A.isLongPressedName(a, b);
    cout<<ans;
}