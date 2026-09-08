class Solution {
public:
    vector<vector<int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    typedef pair<int, int> P;
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc,
                                  int cl) {
        if (img.size() == 0 || img[0].empty()) {
            return {{}};
        }

        int r = img.size();
        int c = img[0].size();

        vector<vector<int>> ans = img;
        queue<P> q;
        q.push({sr, sc});

        int val = img[sr][sc];
        if (val == cl)
            return ans;

        ans[sr][sc] = cl;

        while (!q.empty()) {

            P curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (auto &x : dir) {

                int new_i = x[0] + i;
                int new_j = x[1] + j;

                if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
                    ans[new_i][new_j] == val) {
                    
                    ans[new_i][new_j] = cl;
                    q.push({new_i, new_j});
                }
            }
        }
        return ans;
    }
};