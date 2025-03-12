class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res=letters[0];
        int n=letters.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
           if(letters[mid]>target){
               res=letters[mid];
               r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};