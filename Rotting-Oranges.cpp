class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int ans_t = 0;
        while(!q.empty())
        {
            auto front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;
            q.pop();
            ans_t = max(ans_t,t);
            if(r > 0 && grid[r-1][c] == 1 && !visited[r-1][c]){
                q.push({{r-1,c},t+1});
                visited[r-1][c] = 1;
            }
            if(r+1 < m && grid[r+1][c] == 1 && !visited[r+1][c]){
                q.push({{r+1,c},t+1});
                visited[r+1][c] = 1;
            }
            if(c > 0 && grid[r][c-1] == 1 && !visited[r][c-1]){
                q.push({{r,c-1},t+1});
                visited[r][c-1] = 1;
            }
            if(c+1 < n && grid[r][c+1] == 1 && !visited[r][c+1]){
                q.push({{r,c+1},t+1});
                visited[r][c+1] = 1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }
        return ans_t;
    }
};