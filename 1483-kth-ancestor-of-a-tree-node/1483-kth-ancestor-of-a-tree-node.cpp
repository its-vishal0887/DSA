class TreeAncestor {
public:
    vector<vector<int>>ancestorTabl;
    int row, cols;
    TreeAncestor(int n, vector<int>& parent) {
        row = n;
        cols = log2(n)+1;
        ancestorTabl.resize(row, vector<int>(cols, -1)); 
        for(int i = 0; i < n; i++){
            ancestorTabl[i][0] = parent[i];
        }      
        for(int j = 1; j<cols; j++){
            for(int node = 0; node < n; node++){
                if(ancestorTabl[node][j-1] != -1){
                    ancestorTabl[node][j] = ancestorTabl[ancestorTabl[node][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j<cols; j++){
            if(k & (1 << j)){
                node = ancestorTabl[node][j];
                if(node == -1){
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */