class Solution {
public:
    int solve(vector<vector<int>>& matrix, int sr, int sc,
              vector<vector<int>>& dp) {

        if (sc < 0 || sc >= matrix[0].size())
            return 1e9;

        if (sr == matrix.size() - 1)
            return matrix[sr][sc];

        if (dp[sr][sc] != INT_MAX)
            return dp[sr][sc];

        int left = solve(matrix, sr + 1, sc - 1, dp);
        int down = solve(matrix, sr + 1, sc, dp);
        int right = solve(matrix, sr + 1, sc + 1, dp);

        return dp[sr][sc] = matrix[sr][sc] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int ans = INT_MAX;

        for (int j = 0; j < m; j++) {
            ans = min(ans, solve(matrix, 0, j, dp));
        }

        return ans;
    }
};