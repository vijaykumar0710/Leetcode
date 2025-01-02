class Solution {
public:
    int product=1;
    int add=0;
    int subtractProductAndSum(int n) {
        int digit=n%10;
        product*=digit;
        add+=digit;
       if(n/10>0)subtractProductAndSum(n/10);
        return product-add;
    }
};