class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<31; i++){
            int mask = 1<<i;
            int res = k&mask;
            int cnt = 0;
            
            for(int j=0; j<n; j++){
                int item_res = nums[j] & mask;
                if(item_res)
                    cnt++;
            }

            if(res!=0 && cnt%2==0)
                ans++;
            else if(res==0 && cnt%2!=0)
                ans++;
        }
        return ans;
    }
};