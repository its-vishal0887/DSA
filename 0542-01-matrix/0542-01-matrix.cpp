class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>dir{{0,-1}, {0,1}, {-1,0},{1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        if(arr[0].size() == 0 || arr.empty()) return {};
        int r = arr.size();
        int c = arr[0].size();
        
        queue<P>q;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(arr[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>>ans(r, vector<int>(c, 0));

        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto x: dir){
                    int new_i = x[0] + i;
                    int new_j = x[1] + j;

                    if(new_i >= 0 && new_i <r && new_j >= 0 && new_j < c){
                        if(ans[new_i][new_j] == 0 && arr[new_i][new_j] == 1){
                            ans[new_i][new_j] = ans[i][j] + 1;
                            q.push({new_i, new_j});
                        }
                    }
                }
            }
        }
        return ans;
    }
};