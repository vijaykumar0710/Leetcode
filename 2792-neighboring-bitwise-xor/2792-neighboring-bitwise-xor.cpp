class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XOR=0;
        for(auto &derive:derived){
           XOR^=derive;
        }
        return XOR==0;
    }
};