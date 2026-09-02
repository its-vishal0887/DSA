class Solution {
public:
    int n;
    void dfs(int src, vector<bool>&vis, unordered_map<int,vector<int>>&adjLs){
        vis[src] = true;
        for(int &x : adjLs[src]){
            if(!vis[x]){
                dfs(x, vis, adjLs);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool>vis(n, false);
        unordered_map<int, vector<int>>adjLs;
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adjLs);
                cnt++;
            }
        }

        return cnt;
    }
};