class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        long long sum1=0,sum2=0,zeros1=0,zeros2=0;
        for(int i=0;i<m;i++){
            if(nums1[i]==0){
                sum1++;
                zeros1++;
            }
            else sum1+=nums1[i];
        }
        cout<<sum1<<" "<<zeros1<<endl;
        for(int i=0;i<n;i++){
            if(nums2[i]==0){
                zeros2++;
                sum2++;
            }
            else sum2+=nums2[i];
        }
        cout<<sum2<<" "<<zeros2<<endl;
        if(sum1==sum2){
            return sum1;
        }
         if(sum1>sum2){
            if(zeros2>0){
                return sum1;
            }else{
                return -1;
            }
        }
        if(sum2>sum1){
            if(zeros1>0){
                return sum2;
            }else{
                return -1;
            }
        }
        return -1;
    }
};