class Solution {
public:
    bool solve(int src, unordered_map<int,vector<int>>&adjLS, unordered_map<int,bool>&vis, unordered_map<int,bool>&path, vector<int>&ans){
        vis[src] = true;
        path[src] = true;

        for(auto x : adjLS[src]){
            if(path[x]) return false;
            if(!vis[x]){
                bool res = solve(x, adjLS, vis, path, ans);
                if(!res){
                    return false;
                }
            }
        }
        path[src] = false;
        ans.push_back(src);
        return true;
    }

    vector<int> findOrder(int V, vector<vector<int>>& arr) {
        unordered_map<int,vector<int>>adjLS;
        for(auto x : arr){
            int u = x[0];
            int v = x[1];
            adjLS[u].push_back(v);
        }    

        unordered_map<int,bool>vis;
        unordered_map<int,bool>par;
        vector<int>ans;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                bool res = solve(i, adjLS, vis, par, ans);
                if(!res){
                    return {};
                }
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};