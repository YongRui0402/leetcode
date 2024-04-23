#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows==1 || s.length()<=numRows) return s;

        int movetotal = 2*numRows-2;
        string ans="";
        int step1=movetotal,step2=0;

        for(int i=0;i<numRows;i++){
            ans+=s[i];
            for(int j=i;j<s.length();j+=movetotal){
                if(j+step1<s.length()&&step1!=0)
                    ans+=s[j+step1];
                if(j+step1+step2<s.length()&&step2!=0)
                    ans+=s[j+step1+step2];
            }
            step1-=2;
            step2+=2;

        }
        return ans;
    }
};
int main(){
    string s="A";
    int num=2;
    Solution sol;
    cout<<sol.convert(s,num)<<endl;
}