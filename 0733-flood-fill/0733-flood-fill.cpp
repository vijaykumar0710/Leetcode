class Solution {
public:
int m,n;
    void solve(vector<vector<int>>& image, int sr, int sc, int color,int initial){

        if(sr<0 || sc<0 || sr>=m || sc>=n || image[sr][sc]==color) return;

        if(image[sr][sc]==initial){
         image[sr][sc]=color;

         solve(image,sr+1,sc,color,initial);
         solve(image,sr-1,sc,color,initial);
         solve(image,sr,sc+1,color,initial);
         solve(image,sr,sc-1,color,initial);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

         m=image.size();
         n=image[0].size();

        int initial=image[sr][sc];

         solve(image,sr,sc,color,initial);
         return image;
    }
};