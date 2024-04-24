class Solution {
public:
    int tribonacci(int n) {
        int t0=0,t1=1,t2=1;
        if(n==0)
            return 0;
        else if(n==1||n==2)
            return 1;
        else{
            int t3=t0+t1+t2;
            for(int i=0;i<n-3;i++){
                t0=t1;
                t1=t2;
                t2=t3;
                t3=t0+t1+t2;
            }
            return t3;

        }
        
    }
};