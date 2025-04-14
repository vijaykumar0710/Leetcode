class Solution {
public:
typedef long long ll;

vector<ll>bitcount;

void getBits(ll num){
    if(num==0) return;
    if(num==1){
        bitcount[0]++;
        return;
    }
    ll bitlen=log2(num);
    ll nearestpow2=(1ll<<bitlen);
    bitcount[bitlen]+=(num-nearestpow2+1); //filling lastbit 1-indexed
    for(ll i=0;i<bitlen;i++){         // filling remaining bits
        bitcount[i]+=(nearestpow2/2);
    }
    // filling rightmost part
    num=num-nearestpow2;
    getBits(num);
}

    long long findMaximumNumber(long long k, int x) {
        ll low=0, high=1e15;

        ll result=0;

        while(low<=high){
            ll mid=low+(high-low)/2;
            
            bitcount=vector<ll>(65,0);
            getBits(mid);

            ll accumulatedcount=0;

            for(ll i=0;i<(log2(mid)+1);i++){
                if((i+1)%x==0){
                    accumulatedcount+=bitcount[i];
                }
            }
            if(accumulatedcount<=k){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return result;
    }
};