class Solution {
public:
long long maxi(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>pge(n),nge(n);
    
    for(int i=0;i<n;i++){
      while(!st.empty() && nums[st.top()]<=nums[i]){
        st.pop();
      }
      pge[i]=st.empty()?-1:st.top();
      st.push(i);
    }
   
    while (!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
      while(!st.empty() && nums[st.top()]<nums[i]){
        st.pop();
      }
      nge[i]=st.empty()?n:st.top();
      st.push(i);
    }
   long long sum=0;
   for(int i=0;i<n;i++){
    long long left=i-pge[i];
    long long right=nge[i]-i;
    sum+=(nums[i]*left*right);
   }
   return sum;
}

long long mini(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>pse(n),nse(n);
    
    for(int i=0;i<n;i++){
      while(!st.empty() && nums[st.top()]>=nums[i]){
        st.pop();
      }
      pse[i]=st.empty()?-1:st.top();
      st.push(i);
    }
   
    while (!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
      while(!st.empty() && nums[st.top()]>nums[i]){
        st.pop();
      }
      nse[i]=st.empty()?n:st.top();
      st.push(i);
    }
   long long sum=0;
   for(int i=0;i<n;i++){
    long long left=i-pse[i];
    long long right=nse[i]-i;
    sum+=(nums[i]*left*right);
   }
   return sum;
}
    long long subArrayRanges(vector<int>& nums) {
        long long max_sum=maxi(nums);
        long long min_sum=mini(nums);
        return max_sum-min_sum;
    }
};