class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n_int[1000+50]={0};
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                n_int[-nums[i]]++;
        }
        
        int maxk=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0&&n_int[nums[i]]>0)
                maxk=max(maxk,nums[i]);
        }
        return maxk;    
    }
};