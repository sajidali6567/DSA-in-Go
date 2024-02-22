class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n+1, 0), outgoing(n+1, 0);
        for(auto edge: trust) {
            int a = edge[0], b = edge[1];
            outgoing[a]++; incoming[b]++;
        }
        // if outgoing edge is zero, could be the town judge, incoming edges should be n-1
        for(int i=1;i<=n;i++) {
            if(outgoing[i] == 0) { // trusts no one
                if(incoming[i] == n-1) { // trusted by everyone
                    return i;
                }
            }
        }
        return -1;
    }
};