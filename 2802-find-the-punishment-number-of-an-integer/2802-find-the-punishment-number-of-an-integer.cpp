class Solution {
public:
bool canPartition(string numStr, int target, int start, int currentSum) {
    if (start == numStr.length()) {
        return currentSum == target;
    }
    if(currentSum>target) return false;
    for (int i = start; i < numStr.length(); i++) {
        string sub=numStr.substr(start,i-start+1);
        int val=stoi(sub);
        if (canPartition(numStr, target, i + 1, currentSum + val)) {
            return true;
        }
    }
    return false;
}
    int punishmentNumber(int n) {
        int punishment_number=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            string squareStr=to_string(num);
            if (canPartition(squareStr, i,0,0)) { 
            punishment_number +=num; 
         }
        }
        return punishment_number;
    }
};