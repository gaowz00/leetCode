#include "../head.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int _times = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]){
                _times ++;
            }else{
                _times = 1;
            }
            if( _times > 2){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};