class Solution {
public:
    int longestIdealString(string s, int k) {
        map<char,int> charlenMap;
        int ans=0;
        for(int i=0;i<26;i++)
            charlenMap.insert({'a'+i,0});

        for(int i=s.length()-1;i>=0;i--){

            int maxlen = 0;
            
            for(int j=max((int)'a',s[i]-k);j<=min((int)'z',s[i]+k);j++){
                if(charlenMap[(char)j]>maxlen){
                    maxlen=charlenMap[(char)j];
                }
            }
            charlenMap[s[i]]=maxlen+1;
            ans=max(ans,maxlen+1);
        }
        return ans;
    }
};