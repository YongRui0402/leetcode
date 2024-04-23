class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0) return "";
        int start=0,maxLen=1;
        for(int i=0;i<len;){
            if(len-i<=maxLen/2) break;
            int j=i,k=i;
            while(k<len-1 && s[k]==s[k+1]) k++;
            i=k+1;
            while(k<len-1 && j>0 && s[k+1]==s[j-1]){
                k++;
                j--;
            }
            if(k-j+1>maxLen){
                start=j;
                maxLen=k-j+1;
            }
        }
        return s.substr(start,maxLen);
    }

};