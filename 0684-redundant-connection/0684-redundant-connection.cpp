class Solution {
public:
    vector<int> parents;
    // union function
    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            return;
        }
        parents[pa] = pb; // missing it always and writing a and b instead
    }
    
    int find(int a) {
        if(a == parents[a]) {
            return a;
        }
        return parents[a] = find(parents[a]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.resize(n + 1);
        for(int i=1;i<=n;i++) {
            parents[i] = i;
        }
        
        int x, y; // stores answer
        for(auto edge: edges) {
            int a = edge[0], b = edge[1];
            // check if a and b are already connected, it creates a cycle
            cout << find(a) << " " << find(b) << endl;
            if(find(a) == find(b)) {
                x = a; y =b;
            } else {
                merge(a, b);
            }
        }
        return {x, y};
    }
};