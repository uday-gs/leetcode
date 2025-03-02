class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int starting_color, int color){
        int m = image.size();
        int n = image[0].size();
        image[i][j] = color;
        if(i > 0 && image[i-1][j] == starting_color){
            dfs(image,i-1,j,starting_color,color);
        }
        if(i+1 < m && image[i+1][j] == starting_color){
            dfs(image,i+1,j,starting_color,color);
        }
        if(j > 0 && image[i][j-1] == starting_color){
            dfs(image,i,j-1,starting_color,color);
        }
        if(j+1 < n && image[i][j+1] == starting_color){
            dfs(image,i,j+1,starting_color,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int starting_color = image[sr][sc];
        if(starting_color == color){
            return image;
        }
        dfs(image,sr,sc,starting_color,color);
        return image;
    }
};