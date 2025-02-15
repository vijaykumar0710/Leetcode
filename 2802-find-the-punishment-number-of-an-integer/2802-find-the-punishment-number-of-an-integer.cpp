class Solution {
public:
bool canPartition(string numStr, int target, int start, int currentSum) {
    if (start == numStr.length()) {
        return currentSum == target;
    }
    if(currentSum>target) return false;
    int num = 0;
    for (int i = start; i < numStr.length(); i++) {
        num = num * 10 + (numStr[i] - '0');  
        if (canPartition(numStr, target, i + 1, currentSum + num)) {
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
            punishment_number += (i * i); 
         }
        }
        return punishment_number;
    }
};