class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,m=version1.size(),n=version2.size();
        long long sum1=0,sum2=0;
        
        while(sum1==sum2){
            sum1=0;
            sum2=0;
            if(version1[i]=='.')
                i++;
            if(version2[j]=='.')
                j++;


            while(i<m&&version1[i]!='.'){
                sum1=sum1*10+version1[i]-'0';
                i++;
            }
            while(j<n&&version2[j]!='.'){
                sum2=sum2*10+version2[j]-'0';
                j++;
            }
            // cout << sum1 << " " << sum2 << " "<<i <<" "<<j<<endl;
            if(sum1>sum2)
                return 1;
            else if(sum1<sum2)
                return -1;
            else if(i>=m&&j>=n)
                return 0;
        }

        return 0;
        
    }
};