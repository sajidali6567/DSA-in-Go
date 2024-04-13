class Solution {
public:
    // int ALLONES = (1u << 31)-1;
    int ALLONES = ~0;
    vector<int> parents;
    vector<int> andMap;
    int find(int a) {
        if(a == parents[a]) return a;
        return find(parents[a]);
    }
    
    void merge(int a, int b, int w) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            andMap[pb] &= w;
            return;
        }
        if(pa < pb) {
            parents[pb] = pa;
            andMap[pa] = w & andMap[pa] & andMap[pb];
        } else {
            parents[pa] = pb;
            andMap[pb] = w & andMap[pa] & andMap[pb];
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Initialization
        for(int i=0;i<n;i++) {
            parents.push_back(i);
            andMap.push_back(ALLONES);
        }
        
        // build DSU
        for(auto edge: edges) {
            merge(edge[0], edge[1], edge[2]);
        }
        
        // Query - if the vertices are part of different connnected component, return -1
        // else we need to take the bitwise and of all the edges in connected component
        // not that treeAnd stores the and of all vertices in one component
        vector<int> ans;
        for(auto q:query) {
            int pa = find(q[0]);
            int pb = find(q[1]);
            if(pa != pb) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(andMap[pa]);
        }
            
        return ans;
    }
};