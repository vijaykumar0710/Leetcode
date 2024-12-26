class Solution {
public:
vector<vector<int>>result;
void solve(int n,int k,int i,vector<int>&vec){
   if(k==0){
    result.push_back(vec);
    return;
   }
   if(i>n)return;
   vec.push_back(i);
   solve(n,k-1,i+1,vec);
   vec.pop_back();
   solve(n,k,i+1,vec);
}
    vector<vector<int>> combine(int n, int k) {
    vector<int> vec;
     solve(n,k,1,vec);
     return result;
     }
};