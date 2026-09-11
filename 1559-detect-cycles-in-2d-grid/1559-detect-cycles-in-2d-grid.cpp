class Solution {
public:
    vector<vector<int>>dir{{0,-1}, {0,1},{-1,0},{1,0}};
    int m, n;

    bool cycleDetDFS(int i, int j, int prev_i, int prev_j, vector<vector<bool>>&vis, vector<vector<char>>&grid){
        if(vis[i][j]) return true;
        vis[i][j] = true;

        for(auto x : dir){
            int new_i = i +  x[0];
            int new_j =j + x[1];

            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == grid[i][j]){
                if(new_i == prev_i && new_j == prev_j){
                    continue;
                }
                if(cycleDetDFS(new_i, new_j, i, j, vis, grid)){
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && cycleDetDFS(i, j, -1,-1, vis, grid)){
                    return true;
                }
            }
        }
        return false;
    }
};