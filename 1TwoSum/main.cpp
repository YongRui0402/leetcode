#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numMap;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int loss = target-nums[i];
            if(numMap.count(loss)){
                return {numMap[loss],i};
            }
            numMap[nums[i]]=i;
        }
        return {};
    }
};
int main(){
    
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution sol;
    vector<int> res = sol.twoSum(nums,target);
    for (int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}