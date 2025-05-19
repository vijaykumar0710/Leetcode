class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x=nums[0],y=nums[1],z=nums[2];
        if(x+y>z && y+z>x && x+z>y){
            if(x==y && x==z && y==z) return "equilateral";
            else if((x==y || x==z || y==z) && (x!=y || x!=z || y!=z)) return "isosceles";
            else return "scalene";
        }
        return "none";
    }
};