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