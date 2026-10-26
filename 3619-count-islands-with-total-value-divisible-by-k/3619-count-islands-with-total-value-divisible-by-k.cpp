class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void solve(vector<vector<int>>&arr, int k, int i, int j, int &cnt){
        if(arr[i][j] <= 0) return;
        int r = arr.size();
        int c = arr[0].size();

        queue<p>q;
        q.push({i, j});

        long long sum = arr[i][j];
        arr[i][j] = 0;

        while(!q.empty()){
            p curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for(auto x : dir){
                int new_i = x[0] + i;
                int new_j = x[1] + j;

                if(new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && arr[new_i][new_j] > 0){
                    sum += arr[new_i][new_j];
                    arr[new_i][new_j] = 0;
                    q.push({new_i, new_j});
                }
            }
            
        }
        if(sum % k == 0) cnt++;


    }
    int countIslands(vector<vector<int>>& arr, int k) {
        int cnt = 0;
        for(int i = 0; i<arr.size(); i++){
            for(int j = 0; j<arr[0].size(); j++){       
                solve(arr, k, i, j, cnt);
            }
        }
        return cnt;
    }
};