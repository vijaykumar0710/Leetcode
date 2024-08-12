class Solution {
public:
int m,n;
void dfs(vector<vector<int>>& image, int sr, int sc, int color,int initial){
    if(sr<0 || sc<0 ||sr>=m || sc>=n || image[sr][sc]==color || image[sr][sc]!=initial){
               return;
         }
         initial=image[sr][sc];
        image[sr][sc]=color;
    
        dfs(image,sr,sc+1,color,initial);
        dfs(image,sr,sc-1,color,initial);
        dfs(image,sr+1,sc,color,initial);
        dfs(image,sr-1,sc,color,initial);     
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         m=image.size();
         n=image[0].size();
         int initial=image[sr][sc];
        dfs(image,sr,sc,color,initial); 
        return image;
    }
};