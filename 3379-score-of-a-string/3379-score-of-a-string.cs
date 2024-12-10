public class Solution {
    public int ScoreOfString(string s) {
        int sum=0;
        int len=s.Length;
        for(int i=0;i<len-1;i++){
           sum+=Math.Abs(s[i]-s[i+1]);
        }
        return sum;
    }
}