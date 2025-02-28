class Solution {
public:
bool isDuplicate(string &s1,string &s2){
    int arr[26]={0};
    for(auto &ch:s1){
        if(arr[ch-'a']>0) return true;
        arr[ch-'a']++;
    }
    for(auto &ch:s2){
        if(arr[ch-'a']>0) return true;
        arr[ch-'a']++;
    }
    return false;
}
int solve(int i,vector<string>&arr,string temp,int n){
if(i>=n){
    return temp.size();
}
int include=0,exclude=0;
if(isDuplicate(temp,arr[i])){
    exclude=solve(i+1,arr,temp,n);
}else{ 
  exclude=solve(i+1,arr,temp,n);
  include=solve(i+1,arr,temp+arr[i],n);
  }
  return max(include,exclude);
}
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        int i=0;
        return solve(i,arr,temp,n);
    }
};