class Solution {
public:
    void bfs(int start,int n,vector<int> &visited,vector<vector<int>>& isConnected)
    {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int k = 0;k<n;k++)
            {
                if(!visited[k] && isConnected[cur][k] == 1)
                {
                    q.push(k);
                    visited[k] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i]){
                num++;
                bfs(i,n,visited,isConnected);
            }
        }
        return num;
    }
};