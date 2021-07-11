#include "../head.h"

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int, int> _map;
        for (int i = 0; i < arr.size(); i++) {
            _map[arr[i]]++;
        }
                                                                                                    
    }
};