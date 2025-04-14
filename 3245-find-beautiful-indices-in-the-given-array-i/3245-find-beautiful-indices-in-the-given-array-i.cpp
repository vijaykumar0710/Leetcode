class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int size = s.size();
        int asize = a.size();
        int bsize = b.size();
        
        vector<int> sti, stj;

        // Find all positions of substring a
        for (int i = 0; i <= size - asize; ++i) {
            if (s.compare(i, asize, a) == 0) {
                sti.push_back(i);
            }
        }

        // Find all positions of substring b
        for (int i = 0; i <= size - bsize; ++i) {
            if (s.compare(i, bsize, b) == 0) {
                stj.push_back(i);
            }
        }

        vector<int> res;
     for(int i=0;i<sti.size();i++){
    int left=sti[i]-k;
    int right=sti[i]+k;
    auto it=lower_bound(stj.begin(),stj.end(),left);
    if(it!=stj.end() && *it<=right){
         res.push_back(sti[i]);
            }
         }
        return res;
    }
};
