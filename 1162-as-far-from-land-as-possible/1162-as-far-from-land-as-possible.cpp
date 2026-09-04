class Solution {
public:
    typedef pair<int, int>P;
    vector<vector<int>>dir{{-1, 0}, {1,0}, {0,-1}, {0,1}};
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int r = grid.size();
        int c = grid[0].size();

        int watLand = 0;
        queue<P>q;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j] == 0){
                    watLand++;
                }
                else if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        if(watLand == 0) return -1;
        int dist = -1;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &x : dir){
                    int new_i = x[0] + i;
                    int new_j = x[1] + j;

                    if(new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && grid[new_i][new_j] == 0){
                        grid[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
            dist++;
        }
        return dist;
        
    }
};