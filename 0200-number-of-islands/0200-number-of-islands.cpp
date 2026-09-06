class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>dir{{0,-1},{0,1},{-1,0},{1,0}};

    void solve(vector<vector<char>>&grid, int i, int j){
        if(grid[0].empty() || grid.empty()) return ;
        
        int r = grid.size();
        int c = grid[0].size();

        queue<P>q;
        q.push({i, j});
        grid[i][j] = '0';

        while(!q.empty()){

            P curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for(auto x : dir){
                int new_i = x[0] + i;
                int new_j = x[1] + j;

                if(new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && grid[new_i][new_j] == '1'){
                    grid[new_i][new_j] = '0';
                    q.push({new_i, new_j});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int island = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == '1'){
                    island++;
                    solve(grid, i,j);
                }
            }
        }
        return island;
    }
};