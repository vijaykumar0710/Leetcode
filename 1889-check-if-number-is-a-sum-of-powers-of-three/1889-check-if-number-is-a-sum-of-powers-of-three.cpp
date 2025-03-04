class Solution {
public:
bool knapsack(int n,int p){
    if(n==0) return true;
    if(pow(3,p)>n) return false;
    return (knapsack(n-pow(3,p),p+1) || knapsack(n,p+1));
}
    bool checkPowersOfThree(int n) {
        return knapsack(n,0);
    }
};