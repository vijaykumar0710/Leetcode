class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>&image,int sr,int sc,int color,int origanl_color,int m,int n){
if(sr<0 || sr>=m || sc<0 || sc>=n) return;
if(origanl_color!=image[sr][sc]) return;
image[sr][sc]=color;
for(auto &direction:directions){
    int newRow=sr+direction[0];
    int newCol=sc+direction[1];
    dfs(image,newRow,newCol,color,origanl_color,m,n);
   }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int origanl_color=image[sr][sc];
        if(color!=origanl_color){ 
        dfs(image,sr,sc,color,origanl_color,m,n);
        }
        return image;
    }
};