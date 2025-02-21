class Solution {
public:
    int maximum69Number (int num) {
        string nums=to_string(num);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]=='6'){
                nums[i]='9';
                break;
            }
        }
        return stoi(nums);
    }
};