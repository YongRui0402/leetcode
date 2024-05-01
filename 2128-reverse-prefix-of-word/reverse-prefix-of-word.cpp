class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size(),index=-1;
        string res="";

        for(int i=0; i<n; i++){
            res=word[i]+res;
            if(word[i]==ch){
                index = i;
                break;
            }
        }
        if(index==-1){
            return word;
        }
        else{
            // string res1 = word.substr(0,index+1);
            // reverse(res1.begin(), res1.end());
            string res2=word.substr(index+1); 
            return res+res2;
        }
    }
};