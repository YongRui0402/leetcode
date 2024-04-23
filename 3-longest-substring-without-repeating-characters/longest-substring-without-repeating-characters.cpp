class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0, l=0, max=0;
        int n = s.size();
        int arr[256] = {0};
        while(r < n){
            if(arr[s[r]] == 0){
                arr[s[r]] = 1;
                r++;
                if(r-l > max){
                    max = r-l;
                }
            }else{
                arr[s[l]] = 0;
                l++;
            }
        }
        return max;
    }
};