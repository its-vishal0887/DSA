class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    typedef pair<int, int> P;
    int orangesRotting(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();

        int frestOrnge = 0;
        queue<P> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 2) {
                    q.push({i, j});
                } else if (arr[i][j] == 1) {
                    frestOrnge++;
                }
            }
        }

        if (frestOrnge == 0)
            return 0;

        int mnt = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for (auto& x : dir) {
                    int new_i = i + x[0];
                    int new_j = j + x[1];

                    if ((new_i >= 0) && (new_i < r) && (new_j >= 0) &&
                        (new_j < c) && arr[new_i][new_j] == 1) {
                        arr[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        frestOrnge--;
                    }
                }
            }
            mnt++;
        }
        if (frestOrnge == 0)
            return mnt - 1;
        else
            return -1;
    }
};