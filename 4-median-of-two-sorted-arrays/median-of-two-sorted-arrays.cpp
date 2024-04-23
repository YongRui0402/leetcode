class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int n = n1 + n2;
        int i = 0,j = 0,tmp1=-1e7,tmp2=-1e7,tmp=-1e7;
        bool odd = n%2;

        if(n1==0)
            return odd?nums2[int((n-1)/2)]:(nums2[int(n/2)-1]+nums2[int(n/2)])/2.0;
        else if(n2==0)
            return odd?nums1[int((n-1)/2)]:(nums1[int(n/2)-1]+nums1[int(n/2)])/2.0;
            
        while(1){
            if(i<n1 && j<n2){
                if(nums1[i] < nums2[j]){
                    tmp = nums1[i];
                    i++;
                }else{
                    tmp = nums2[j];
                    j++;
                }
            }else if(i<n1){
                tmp = nums1[i];
                i++;
            }else if(j<n2){
                tmp = nums2[j];
                j++;
            }
            if(tmp>tmp1){
                tmp2 = tmp1;
                tmp1 = tmp;
            }else if(tmp>tmp2){
                tmp2 = tmp;
            }
            
            if(i+j == int(n/2)+1){
                break;
            }
        }
        return odd?tmp1:(tmp1+tmp2)/2.0;
    }
};