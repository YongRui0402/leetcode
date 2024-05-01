class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1;
        string res="";

        for(int i=0; i<word.size(); i++){
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
            return res+word.substr(index+1);
        }
    }
};