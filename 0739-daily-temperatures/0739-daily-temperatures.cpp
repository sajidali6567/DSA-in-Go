class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack;
        vector<int> ans;
        int n = temperatures.size();
        // start from end, and maintain the monotonic stack of maximum elements
        for(int i = n-1; i>=0; i--) {
            int temp = temperatures[i];
            while(!stack.empty() && temp >= stack.top().first) {
                stack.pop();
            }
            if(stack.empty()) ans.push_back(0); else ans.push_back({stack.top().second - i});
            stack.push({temp, i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};