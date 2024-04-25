class Solution {
public:
    int longestIdealString(string s, int k) {
        int charlenMap[26] = {0};
        int ans = 0;

        for(int i=s.length()-1;i>=0;i--){
            int maxlen = 0,start=max(s[i]-'a'-k,0),end=min(s[i]-'a'+k,25);
            for(int j=start;j<=end;j++){
                if(charlenMap[j]>maxlen){
                    maxlen=charlenMap[j];
                }
            }
            charlenMap[s[i]-'a'] = maxlen+1;
            if(maxlen+1>ans)
                ans = max(ans,maxlen+1);
        }
        return ans;
    }
};